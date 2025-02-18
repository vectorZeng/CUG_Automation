#include "sortstu.h"
#include "ui_sortstu.h"

sortstu::sortstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortstu)
{
    ui->setupUi(this);

    readFile();//读文件
    processStu();//求总分
    ui->sortbtn->setFocus();


    this->model=new QStandardItemModel;//表格模型
    this->ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);

    this->model2=new QStandardItemModel;//表格模型
    this->ui->tableView2->setModel(model2);
    ui->tableView->setSortingEnabled(true);

    this->model3=new QStandardItemModel;//表格模型
    this->ui->tableView3->setModel(model3);
    ui->tableView->setSortingEnabled(true);
}

sortstu::~sortstu()
{
    delete model;
    delete model2;
    delete model3;
    delete ui;
}

//-----------------------------------------------------
class Student//开始写继承XXX//学生信息
{
public:
    QString id,name,sex,age,stuClass;
    virtual int sortStu(int way)=0;//按排序方式排序//纯虚函数

    int sortTable(int way)
    {
        return sortStu(way);
    }
};

class StudentS:public Student//小学生
{
public:
    QString Emark,Mmark,Cmark;
    virtual int sortStu(int way)//按照way排序
    {
        return way+5;//返回排序对应列
    }
};

class StudentM:public Student//中学生
{
public:
    QString Emark,Mmark,Cmark,Gmark,Hmark;
    virtual int sortStu(int way)//按照way排序
    {
        return way+5;//返回排序对应列
    }
};

class StudentL:public Student//大学生
{
public:
    QString major,Emark,Pmark,Mmark;
    virtual int sortStu(int way)//按照way排序
    {
        return way+6;//返回排序对应列
    }
};
//----------------------------------------------------------------


void sortstu::on_sortbtn_clicked()//点击排序
{
    int flag;//要排的列，升序或降序
    //已经获取过what了
    flag=ui->sortflag->currentIndex();//
    int way=ui->sortway->currentIndex();
    if(way==0||what==0)
    {
        QMessageBox::warning(this,"提示","请选择排序方式");
        return;
    }
    if(what==1)//小学生
    {
        Student *stu=new StudentS;//建一个学生类指针
        col=stu->sortTable(way);//得到要排的序号
        delete stu;
    }
    else if(what==2)//中学生
    {
        Student *stu=new StudentM;//建一个学生类指针
        col=stu->sortTable(way);
        delete stu;
    }
    else if(what==3)//大学生
    {
        Student *stu=new StudentL;//建一个学生类指针
        col=stu->sortTable(way);
        delete stu;
    }

    //设置对应搜索条件的表头
    this->model3->
    setHorizontalHeaderItem(0,new QStandardItem(this->model->headerData(col,Qt::Horizontal).toString()));
    docopy();//复制对应列
    //排序在这里!!!!!!!!!!!!!!!!!!!!!---------------------------------------------------------------
    if(flag==1)//降序
    {
        this->model->sort(col,Qt::DescendingOrder);
        this->model3->sort(0,Qt::DescendingOrder);

    }
    else if(flag==0)//升序
    {
        this->model->sort(col,Qt::AscendingOrder);
        this->model3->sort(0,Qt::AscendingOrder);
    }

}
void sortstu::docopy()//复制对应列信息到model3
{
    for(int i=0;i<sum;i++)//行
    {
        QString temp=model->data(model->index(i,col)).toString();
        QStandardItem *item=new QStandardItem(temp);
        item->setData(temp.toDouble(),Qt::DisplayRole);
        this->model3->setItem(i,0,item);
    }
}







//下面是一堆函数！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
void sortstu::readFile()//读文件
{
    stu_lines.clear();//清空
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))//打开不成功
    {
        QMessageBox::critical(this,"错误","文件打开失败");
        this->close();//关闭窗口
    }
    QTextStream in(&file);

    while(!in.atEnd())//没读到文件尾则继续读
    {
          QString line =in.readLine();//读取一行
          stu_lines.append(line);//每行都存放到list中
    }
    file.close();//关闭
}
void sortstu::cleartable(int what)//清空并设置表头
{
    this->model->clear();
    this->model2->clear();
    this->model3->clear();
    this->model->setHorizontalHeaderItem(0,new QStandardItem("就读状况"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("班级"));
    if(what==1)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("数学成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("语文成绩"));
        this->model->setHorizontalHeaderItem(9,new QStandardItem("总分"));

        this->model2->setHorizontalHeaderItem(0,new QStandardItem("英语平均分"));
        this->model2->setHorizontalHeaderItem(1,new QStandardItem("数学平均分"));
        this->model2->setHorizontalHeaderItem(2,new QStandardItem("语文平均分"));
        this->model2->setHorizontalHeaderItem(3,new QStandardItem("总分平均分"));
    }
    else if(what==2)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("数学成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("语文成绩"));
        this->model->setHorizontalHeaderItem(9,new QStandardItem("地理成绩"));
        this->model->setHorizontalHeaderItem(10,new QStandardItem("历史成绩"));
        this->model->setHorizontalHeaderItem(11,new QStandardItem("总分"));

        this->model2->setHorizontalHeaderItem(0,new QStandardItem("英语平均分"));
        this->model2->setHorizontalHeaderItem(1,new QStandardItem("数学平均分"));
        this->model2->setHorizontalHeaderItem(2,new QStandardItem("语文平均分"));
        this->model2->setHorizontalHeaderItem(3,new QStandardItem("地理平均分"));
        this->model2->setHorizontalHeaderItem(4,new QStandardItem("历史平均分"));
        this->model2->setHorizontalHeaderItem(5,new QStandardItem("总分平均分"));
    }
    else if(what==3)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("专业"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("程序成绩"));
        this->model->setHorizontalHeaderItem(9,new QStandardItem("高数成绩"));
        this->model->setHorizontalHeaderItem(10,new QStandardItem("总分"));

        this->model2->setHorizontalHeaderItem(0,new QStandardItem("英语平均分"));
        this->model2->setHorizontalHeaderItem(1,new QStandardItem("程序平均分"));
        this->model2->setHorizontalHeaderItem(2,new QStandardItem("高数平均分"));
        this->model2->setHorizontalHeaderItem(3,new QStandardItem("总分平均分"));
    }
}
void sortstu::processStu()//求总分
{
    memset(a,0,sizeof(a));
    for(int i=0;i<stu_lines.length();i++)//遍历容器
    {
        QString line =stu_lines.at(i),source=stu_lines.at(i);//取出信息
        line=line.trimmed();//去掉空字符
        QStringList subs=line.split(" ");//按空格分开
        QString cnt;
        double total;
        if(subs.at(0)=="小学生")
        {
            total=subs[6].toDouble()+subs[7].toDouble()+subs[8].toDouble();
            a[0][0]+=subs[6].toDouble();//求英语总分
            a[0][1]+=subs[7].toDouble();
            a[0][2]+=subs[8].toDouble();
            a[0][3]+=total;//求总分
        }
        else if(subs.at(0)=="中学生")
        {
            total=subs[6].toDouble()+subs[7].toDouble()+subs[8].toDouble()
                    +subs[9].toDouble()+subs[10].toDouble();
            a[1][0]+=subs[6].toDouble();//求英语总分
            a[1][1]+=subs[7].toDouble();
            a[1][2]+=subs[8].toDouble();
            a[1][3]+=subs[9].toDouble();
            a[1][4]+=subs[10].toDouble();
            a[1][5]+=total;//求总分
        }
        else if(subs.at(0)=="大学生")
        {
            total=subs[7].toDouble()+subs[8].toDouble()+subs[9].toDouble();
            a[2][0]+=subs[7].toDouble();//求英语总分
            a[2][1]+=subs[8].toDouble();
            a[2][2]+=subs[9].toDouble();
            a[2][3]+=total;//求总分
        }
        cnt=QString::number(total, 'f', 0);//保留0位小数
        stu_lines.replace(i,source+" "+cnt);//替换list第i行
    }
    //已经算完各个分数相加

}

void sortstu::on_sortwhat_currentIndexChanged(int index)//选择就读情况
{
    what=index;
    sum=0;//初始化
    if(index==0)//清空信息
    {
        ui->sumShow1->setText("XXX");
        ui->sumShow2->setText("XX");
        this->model->clear();
        this->model2->clear();
        this->model3->clear();
        ui->sortway->clear();ui->sortway->addItem("请先选择上一项");
    }
    else if(index==1)//小学生
    {
        disPlayAll();
        ui->sumShow1->setText("小学生");
        ui->sortway->clear();ui->sortway->addItem("请选择排序方式");
        ui->sortway->addItem("按英语成绩排序");ui->sortway->addItem("按数学成绩排序");
        ui->sortway->addItem("按语文成绩排序");ui->sortway->addItem("按总分成绩排序");
    }
    else if(index==2)//中学生
    {
        disPlayAll();
        ui->sumShow1->setText("中学生");
        ui->sortway->clear();ui->sortway->addItem("请选择排序方式");
        ui->sortway->addItem("按英语成绩排序");ui->sortway->addItem("按数学成绩排序");
        ui->sortway->addItem("按语文成绩排序");ui->sortway->addItem("按地理成绩排序");
        ui->sortway->addItem("按历史成绩排序");ui->sortway->addItem("按总分成绩排序");
    }
    else if(index==3)//大学生
    {
        disPlayAll();
        ui->sumShow1->setText("大学生");
        ui->sortway->clear();ui->sortway->addItem("请选择排序方式");
        ui->sortway->addItem("按英语成绩排序");ui->sortway->addItem("按程序成绩排序");
        ui->sortway->addItem("按高数成绩排序");ui->sortway->addItem("按总分成绩排序");
    }
    if(index!=0) ui->sumShow2->setText(QString::number(sum));//设置人数
    disPlayAve();
}
void sortstu::disPlayAll()//显示小中大
{
    cleartable(what);
    int row=0;//从第一行开始显示
    for(int i=0;i<stu_lines.length();i++)//遍历容器
    {
        QString line =stu_lines.at(i);//取出信息
        line=line.trimmed();//去掉空字符
        QStringList subs=line.split(" ");//按空格分开
        if(subs.at(0)==ui->sortwhat->currentText())//符合就读情况
        {
            sum++;
            disPlay(row++,subs);
        }
    }
}
void sortstu::disPlay(int row,QStringList subs)//显示一行信息
{
    for(int i=0;i<subs.length();i++)
    {
        if(what==3&&i==6||i<6)
        {
            this->model->setItem(row,i,new QStandardItem(subs.at(i)));//传递字符串
        }
        else//传入数值才能排成绩
        {
            QStandardItem *item=new QStandardItem(subs.at(i));
            item->setData(subs.at(i).toDouble(),Qt::DisplayRole);
            this->model->setItem(row,i,item);
        }
    }

}
void sortstu::disPlayAve()//显示平均分
{
    //cnt=QString::number(total, 'f', 0);//保留0位小数
    if(what==1)//小学生
    {
        for(int i=0;i<4;i++)//4列信息
        {
            double b=a[0][i]/sum;
            QString item=QString::number(b,'f',1);
            this->model2->setItem(0,i,new QStandardItem(item));//传递字符串
        }
    }
    else if(what==2)//中学生
    {
        for(int i=0;i<6;i++)//6列信息
        {
            double b=a[1][i]/sum;
            QString item=QString::number(b,'f',1);
            this->model2->setItem(0,i,new QStandardItem(item));//传递字符串
        }
    }
    else if(what==3)//大学生
    {
        for(int i=0;i<4;i++)//4列信息
        {
            double b=a[2][i]/sum;
            QString item=QString::number(b,'f',1);
            this->model2->setItem(0,i,new QStandardItem(item));//传递字符串
        }
    }
}
