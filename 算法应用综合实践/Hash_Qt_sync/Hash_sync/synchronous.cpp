#include "synchronous.h"
#include<QDir>
#include<QFile>
#include<QFileInfo>
#include<QDebug>
#include<QTime>
#include <iterator>
//构造函数
Synchronous::Synchronous(QString ohtpath, QString ohtspath, QObject *parent)
{
    //默认单向自动更新
    way=one_way;
    Automatic=true;             //单向自动
    Pre_mode=Left;

    this->ohtpath= ohtpath;
    this->ohtspath= ohtspath;
    oht=new Ordered_Hash_Tree(ohtpath);
    ohts=new Ordered_Hash_Tree(ohtspath);
    l=this->Compare_OHT(oht->getRN(),ohts->getRN());
    //进行文件监视器的初始化
    ohtWatcher=new QFileSystemWatcher(parent);
    ohtsWatcher=new QFileSystemWatcher(parent);

    //当文件发生改变时(左侧)
    connect(ohtWatcher,&QFileSystemWatcher::fileChanged,
            [=](const QString &path)
    {
           qDebug() << "ohtWatcher path = " << path;
           qDebug()<<path<<QTime::currentTime().toString();
           if(way==two_way&&Automatic==false)//只有双向且定时处理时才存在文件的冲突
             QMap<QString, QTime>::iterator i=ohtmodifications.insert(path,QTime::currentTime());

    });

    //当目录发生改变时（左侧）
    connect(ohtWatcher,&QFileSystemWatcher::directoryChanged,
            [=](const QString &path)
    {
        qDebug() << "ohtWatcher path = " << path;
        if(Automatic)//单向双向都是这边到另外一边
        {
            ohtWatcher->removePaths(oht->paths);
            ohtsWatcher->removePaths(ohts->paths);
            oht->Rebuild();
            l=this->Compare_OHT(oht->getRN(),ohts->getRN());
            this->solvefile(oht,ohts);
            ohts->Rebuild();
            ohtWatcher->addPaths(oht->paths);
            ohtsWatcher->addPaths(ohts->paths);
        }
    });

     //当文件发生改变时(右侧)
    connect(ohtsWatcher,&QFileSystemWatcher::fileChanged,
            [=](const QString &path)
    {

        qDebug() << "ohtsWatchers path = " << path;
        qDebug()<<path<<QTime::currentTime().toString();
        if(way==two_way&&Automatic==false)//只有双向且定时处理时才存在文件的冲突
          QMap<QString, QTime>::iterator i=ohtsmodifications.insert(path,QTime::currentTime());
     });

    //当目录发生改变时（右侧）
    connect(ohtsWatcher,&QFileSystemWatcher::directoryChanged,
            [=](const QString &path)
    {
        qDebug() << "ohtsWatchers path = " << path;
        if(Automatic&&way==two_way)//单向双向都是这边到另外一边
        {
            ohtWatcher->removePaths(oht->paths);
            ohtsWatcher->removePaths(ohts->paths);
            ohts->Rebuild();
            l=this->Compare_OHT(ohts->getRN(),oht->getRN());
            this->solvefile(ohts,oht);
            oht->Rebuild();
            ohtWatcher->addPaths(oht->paths);
            ohtsWatcher->addPaths(ohts->paths);
        }
    });
}

//析构函数
Synchronous::~Synchronous()
{
    if(oht!=NULL)
        delete oht;
    if(ohts!=NULL)
        delete ohts;
    l.clear();
}

//比较函数返回文件差异集合
QList<FileNode> Synchronous::Compare_OHT(HashNode *subOHT,HashNode *subOHTs)
{
    QList<FileNode> l;
    HashNode *node=subOHT->FistChild;
    HashNode *nodes=subOHTs->FistChild;
    while(subOHT->h!=subOHTs->h&&(node!=NULL||nodes!=NULL))
    {
       if(node==NULL&&nodes!=NULL)
       {

           Remove_Sub_OHT(nodes,l);
           nodes=nodes->NextSibling;
       }
       else if(node!=NULL&&nodes==NULL)
       {
           Add_Sub_OHT(node,l);
           node=node->NextSibling;
       }else if (node->path> nodes->path)
       {
           Remove_Sub_OHT(nodes,l);
           nodes=nodes->NextSibling;
       }
       else if (node->path< nodes->path)
       {
           Add_Sub_OHT(node,l);
           node=node->NextSibling;
       }
       else if (node->path==nodes->path&&node->h==nodes->h)
       {
           node=node->NextSibling;
           nodes=nodes->NextSibling;
       }
       else if (node->path==nodes->path&&node->h!=nodes->h)
       {
           Update_Sub_OHT(node,nodes,l);
           node=node->NextSibling;
           nodes=nodes->NextSibling;
       }

    }

    return l;
}
//采用递归的方法,加
void Synchronous::Add_Sub_OHT(HashNode *subOHT,QList<FileNode>&l)
{
    FileNode f;
    f.op_Path=subOHT->path;
    f.sloveMode=Add;
    l.push_back(f);
    HashNode *node=subOHT->FistChild;
    while (node!=NULL)
    {
        Add_Sub_OHT(node,l);
        node=node->NextSibling;
    }

}

//减
void Synchronous::Remove_Sub_OHT(HashNode *subOHT,QList<FileNode>&l)
{
     HashNode *node=subOHT->FistChild;
     while (node!=NULL)
     {
         Remove_Sub_OHT(node,l);
         node=node->NextSibling;
     }
     FileNode f;
     f.op_Path=subOHT->path;
     f.sloveMode=Remove;
     l.push_back(f);
}

//更新
void Synchronous::Update_Sub_OHT(HashNode *subOHT,HashNode *subOHTs,QList<FileNode>&l)
{
    HashNode *node=subOHT->FistChild;
    HashNode *nodes=subOHTs->FistChild;
    if (node==NULL&&nodes==NULL)
    {
        FileNode f;
        f.op_Path=subOHTs->path;
        f.sloveMode=Update;
        l.push_back(f);
    }
    else
    {
        QList<FileNode> ls=Compare_OHT(subOHT,subOHTs);
        l.append(ls);
    }
}

//进行一开始的文件监视，并进行同步
void Synchronous::solve()
{
    this->solvefile(oht,ohts);
    ohtWatcher->addPaths(oht->paths);
    ohts->Rebuild();
    ohtsWatcher->addPaths(ohts->paths);
}

//进行同步
void Synchronous::solvefile(Ordered_Hash_Tree *oht, Ordered_Hash_Tree *ohts)
{
    for(int i=0;i<l.size();i++)
    {
       FileNode f=l.at(i);
       QString p1=oht->abspath+f.op_Path;
       QString p2=ohts->abspath+f.op_Path;
       if(f.sloveMode==Add)//进行创建
       {
           QFileInfo file1(oht->abspath+f.op_Path);
           //说明两者存在文件冲突
           if(Automatic==false&&file1.isFile()&&ohtmodifications.contains(p1)&&ohtsmodifications.contains(p2))
           {
               if(Pre_mode==Right)//右侧优先，则就是左侧采用删除
               {
                   Delete(oht,f);

               }else if (Pre_mode==New)//这就看那个文件后改，如果是左侧后这就是加，右侧后这就是删除
               {
                       QTime t1= ohtmodifications.value(p1);
                       QTime t2= ohtsmodifications.value(p2);
                       if(t1<t2)//右侧晚
                       {
                           Delete(oht,f);
                       }else
                       {
                           Creat(ohts,f);
                       }

               }
               return;
           }

           this->Creat(ohts,f);
       }
       else if (f.sloveMode==Remove)//进行删除
       {
          QFileInfo file1(ohts->abspath+f.op_Path);
          //说明两者存在文件冲突
          if(Automatic==false&&file1.isFile()&&ohtmodifications.contains(p1)&&ohtsmodifications.contains(p2))
          {
              if(Pre_mode==Right)//右侧优先，则就是左侧采用删除
              {
                  Creat(oht,f);

              }else if (Pre_mode==New)//这就看那个文件后改，如果是左侧后这就是加，右侧后这就是删除
              {
                      QTime t1= ohtmodifications.value(p1);
                      QTime t2= ohtsmodifications.value(p2);
                      if(t1<t2)//右侧晚
                      {
                          Creat(oht,f);
                      }else
                      {
                          Delete(ohts,f);
                      }

              }
              return;
          }


          this->Delete(ohts,f);

       }
       else //进行更新
       {
           //存在文件矛盾
           if(Automatic==false&&ohtmodifications.contains(p1)&&ohtsmodifications.contains(p2))
           {
               if(Pre_mode==Right)//右侧优先，则就是左侧采用删除
               {
                  this->Modify(ohts,oht,f);

               }else if (Pre_mode==New)//这就看那个文件后改，如果是左侧后这就是加，右侧后这就是删除
               {
                       QTime t1= ohtmodifications.value(p1);
                       QTime t2= ohtsmodifications.value(p2);
                       if(t1<t2)//右侧晚,则右侧优先
                       {
                           this->Modify(ohts,oht,f);
                       }else
                       {
                           this->Modify(oht,ohts,f);
                       }

               }
               return;
           }

          this->Modify(oht,ohts,f);
       }
    }
}
//Tree为需要操作的树，创建、删除、更新
void Synchronous::Creat(Ordered_Hash_Tree *Tree, FileNode f)
{
    QFileInfo file;
    QString path;
    if(Tree==oht)//如果需要操作的是左侧的树
    {
        path=oht->abspath+f.op_Path;
        file.setFile(ohts->abspath+f.op_Path);
    }else//需要操作的是右侧的树
    {
        path=ohts->abspath+f.op_Path;
        file.setFile(oht->abspath+f.op_Path);
    }

    if(file.isDir())//如果是目录
    {
        QDir dir(path);
        dir.mkdir(path);
    }
    else if(file.isFile()) //如果是文件
    {
        QFile ordfile(file.absoluteFilePath());
        QFile newfile(path);
        if(ordfile.open(QIODevice::ReadOnly)&&newfile.open(QIODevice::WriteOnly))
        {
            while (!ordfile.atEnd())
            {
                QByteArray bffter= ordfile.read(1000);
                newfile.write(bffter);
            }
          ordfile.close();
          newfile.close();
        }

     }
}

void Synchronous::Delete(Ordered_Hash_Tree *Tree, FileNode f)
{
    QFileInfo file(Tree->abspath+f.op_Path);


    if(file.isDir())//如果是目录
    {
        QDir dir(Tree->abspath+f.op_Path);
        dir.rmdir(Tree->abspath+f.op_Path);

    }
    else if(file.isFile()) //如果是文件
    {
         QFile newfile(Tree->abspath+f.op_Path);
         newfile.remove();
    }
}

void Synchronous::Modify(Ordered_Hash_Tree *oht,Ordered_Hash_Tree *ohts,FileNode f)
{
    QFile ordfile(oht->abspath+f.op_Path);
    QFile newfile(ohts->abspath+f.op_Path);
    if(ordfile.open(QIODevice::ReadOnly)&&newfile.open(QIODevice::WriteOnly))
    {
        while (!ordfile.atEnd())
        {
            QByteArray bffter= ordfile.read(1000);
            newfile.write(bffter);
        }
      ordfile.close();
      newfile.close();
    }
}
//判断相等
bool Synchronous::isDifferent(QString p1, QString p2)
{
    if((p1==ohtpath)&&(p2==ohtspath))//表示相同
    {
        return false;
    }
    return true;
}
//重新进行新的文件夹同步
void Synchronous::Reset(QString ohtpath, QString ohtspath)
{
    //默认单向自动更新
    way=one_way;
    Automatic=true;             //单向自动
    Pre_mode=Left;
    ohtWatcher->removePaths(oht->paths);
    ohtsWatcher->removePaths(ohts->paths);
    this->ohtpath= ohtpath;
    this->ohtspath= ohtspath;
    ohtmodifications.clear();
    ohtsmodifications.clear();

    oht->ResetTree(ohtpath);
    ohts->ResetTree(ohtspath);
    l=this->Compare_OHT(oht->getRN(),ohts->getRN());

}



//定时器
void Synchronous::timerEvent(QTimerEvent *event)
{
    //文件监视器删除原来的文件，两棵树进行重建，然后文件监视器开始监视新文件
    ohtWatcher->removePaths(oht->paths);
    ohtsWatcher->removePaths(ohts->paths);
    oht->Rebuild();
    ohts->Rebuild();
    l=this->Compare_OHT(oht->getRN(),ohts->getRN());
    this->solvefile(oht,ohts);
    oht->Rebuild();
    ohts->Rebuild();
    ohtWatcher->addPaths(oht->paths);
    ohtsWatcher->addPaths(ohts->paths);
    ohtmodifications.clear();
    ohtsmodifications.clear();
    qDebug()<<"定时器开啦";
}























