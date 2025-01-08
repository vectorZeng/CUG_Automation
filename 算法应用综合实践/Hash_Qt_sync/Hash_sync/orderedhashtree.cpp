#include "orderedhashtree.h"
#include<QFileInfo>
#include<QDir>
#include<QDebug>
#include<QStack>
//构造函数
Ordered_Hash_Tree::Ordered_Hash_Tree(QString path)
{

    this->RN=Build_OHT(path,NULL);
    abspath=path;

}
//析构函数
Ordered_Hash_Tree::~Ordered_Hash_Tree()
{
     if(RN!=NULL)
         clear(RN);
     abspath.clear();
}

//建树采用递归的方法,思考是否需要返回值,传进来的参数是什么比较好
HashNode *Ordered_Hash_Tree::Build_OHT(QString absPath,QString Relativepath)
{
    QFileInfo file(absPath);
    HashNode *f=new HashNode;
    paths.append(absPath);//添加进文件监视的路径
    //用于一开始
    if(Relativepath==NULL)
      f->path="/";
    else
    {
        f->path=Relativepath;
    }
    //如果f是目录
    if(file.isDir())
    {
        QDir dir(absPath);
        QStringList infolist = dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
        for(int i=0;i<infolist.size();i++)
        {
            HashNode *node=NULL;
            QString path;
            path=absPath+"/"+infolist.at(i);
            node=Build_OHT(path,Relativepath+"/"+infolist.at(i));
            node->path=Relativepath+"/"+infolist.at(i);
            sortTree(f,node);
        }

        HashNode *p=f->FistChild;
        QString  str;
        while (p!=NULL)
        {
            str+=p->h+p->path;
            p=p->NextSibling;
        }
       f->h=QCryptographicHash::hash(str.toLatin1(),QCryptographicHash::Md5);
    //  qDebug()<<f->path<<f->h.toHex().constData();
    }
    else if (file.isFile()) //如果f是文件
    {
       //需要读文件，来判断文件是否被修改过
        QFile theFile(absPath);
        theFile.open(QIODevice::ReadOnly);
        QByteArray arr;
        while(!theFile.atEnd())
        {
            arr+=theFile.read(1000);
        }
        f->h = QCryptographicHash::hash(arr, QCryptographicHash::Md5);
        theFile.close();
        //qDebug()<<f->path<<f->h.toHex().constData();
       //得到Hash值
    }

    return f;
}

//针对做处理，进行排序链接,其中node是rn直属目录的根节点
void Ordered_Hash_Tree::sortTree(HashNode *rn,HashNode *node)
{
    //2.1
   if(rn->FistChild==NULL)
   {
       rn->FistChild=node;
       node->Parent=rn;
   }else
   {
       HashNode *chNode=rn->FistChild;
       //2.2
       if(node->path<chNode->path)
       {

           rn->FistChild=node;
           node->Parent=rn;

       }else
       {

           //2.3
           while (chNode!=NULL)
           {
              if(chNode->NextSibling==NULL)
               {
                   chNode->NextSibling=node;
                   node->Parent=rn;
                   return;
               }
               else
               {
                   HashNode *nextNode=chNode->NextSibling;

                   if(node->path<nextNode->path)
                   {
                       chNode->NextSibling=node;
                       node->NextSibling=nextNode;
                       node->Parent=rn;
                       break;
                   }
                   else
                   {
                       chNode=nextNode;
                   }
               }
           }

       }

   }

}

void Ordered_Hash_Tree::clear(HashNode *node)
{
    if(node!=NULL)
    {
        HashNode *ch=node->FistChild;
        HashNode *next=node->NextSibling;
        delete node;
        clear(ch);
        clear(next);
    }

}

//重新建树针对，新的文件夹
void Ordered_Hash_Tree::ResetTree(QString path)
{
    paths.clear();
    this->clear(RN);
    this->RN=Build_OHT(path,NULL);
    abspath=path;
}
//重新建树，老的文件夹
void Ordered_Hash_Tree::Rebuild()
{
    paths.clear();
    this->clear(RN);
    this->RN=Build_OHT(abspath,NULL);
}
//得到根节点
HashNode *Ordered_Hash_Tree::getRN()
{
    return this->RN;
}






















