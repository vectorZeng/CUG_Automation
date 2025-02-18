#include "changestu.h"
#include "ui_changestu.h"

changestu::changestu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changestu)
{
    ui->setupUi(this);
}

changestu::~changestu()
{
    delete ui;
}
void changestu::changeShow(QString idline,QStringList stu_line)
{
    idLine=idline;//得到对应行信息
    stu_lines=stu_line;//得到全部信息列表
    processStu(idLine);

}
void changestu::processStu(QString idLine)//处理得到的信息填到表上
{
    QStringList subs=idLine.split(" ");//按空格分开
    QString what =subs[0];//就读情况
    ui->lid->setText(subs[1]);//学号
    ui->lid->setEnabled(false);//学号不可修改
    ui->lname->setText(subs[2]);//姓名
    if(subs[3]=="男") ui->male->setChecked(true);//性别
    else if(subs[3]=="女") ui->female->setChecked(true);
    for(int i=0;i<ui->lage->count();i++)//年龄,count返回选项数量
    {
        if(subs[4]==ui->lage->itemText(i))
        {
            ui->lage->setCurrentIndex(i);//选中对应序号年龄
            break;
        }
    }
    for(int i=0;i<ui->lstuclass->count();i++)//班别
    {
        if(subs[5]==ui->lstuclass->itemText(i))
        {
            ui->lstuclass->setCurrentIndex(i);//选中对应序号班别
            break;
        }
    }
    //以下处理小中大学生
    if(what=="小学生")
    {
        ui->stus->setChecked(true);//选中小学生
        ui->stus_Emark->setText(subs[6]);
        ui->stus_Mmark->setText(subs[7]);
        ui->stus_Cmark->setText(subs[8]);
    }
    else if(what=="中学生")
    {
        ui->stum->setChecked(true);//选中中学生
        ui->stum_Emark->setText(subs[6]);
        ui->stum_Mmark->setText(subs[7]);
        ui->stum_Cmark->setText(subs[8]);
        ui->stum_Gmark->setText(subs[9]);
        ui->stum_Hmark->setText(subs[10]);
    }
    else if(what=="大学生")
    {
        ui->stul->setChecked(true);//选中中学生
        for(int i=0;i<ui->major->count();i++)//专业
        {
            if(subs[6]==ui->major->itemText(i))
            {
                ui->major->setCurrentIndex(i);//选中对应序号班别
                break;
            }
        }
        ui->stul_Emark->setText(subs[7]);
        ui->stul_Pmark->setText(subs[8]);
        ui->stul_Mmark->setText(subs[9]);
    }
}

void changestu::on_btncancel_clicked()//取消修改
{
    this->close();
}

void changestu::on_btnok_clicked()//确认修改
{
    QString cnt;//最终信息
    QString name=this->ui->lname->text();//获取信息
    QString id=this->ui->lid->text();
    QString sex;
    QString age=this->ui->lage->currentText();
    QString stuclass=this->ui->lstuclass->currentText();
    int flag=1;//初始化为信息无误
    int checkMark=1;//检查是否填写完成绩
    //下面为判断性别
    if(this->ui->male->isChecked())//点击男
    {
        sex="男";
    }
    else if(this->ui->female->isChecked())//点击女
    {
        sex="女";
    }
    //下面为判断学生就读情况
    if(this->ui->stus->isChecked())//点击小学生
    {
        if(ui->stus_Emark->text()==""||ui->stus_Mmark->text()==""||ui->stus_Cmark->text()=="")
            checkMark=0;
        cnt="小学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+this->ui->stus_Emark->text()
                +" "+this->ui->stus_Mmark->text()+" "+this->ui->stus_Cmark->text()+"\n";
    }
    else if(this->ui->stum->isChecked())//点击中学生
    {
        if(ui->stum_Emark->text()==""||ui->stum_Mmark->text()==""||ui->stum_Cmark->text()==""
                ||ui->stum_Gmark->text()==""||ui->stum_Hmark->text()=="") checkMark=0;
        cnt="中学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+this->ui->stum_Emark->text()
                +" "+this->ui->stum_Mmark->text()+" "+this->ui->stum_Cmark->text()+" "+
                this->ui->stum_Gmark->text()+" "+this->ui->stum_Hmark->text()+"\n";
    }
    else if(this->ui->stul->isChecked())//点击大学生
    {
        if(ui->stul_Emark->text()==""||ui->stul_Pmark->text()==""||ui->stul_Mmark->text()=="")
            checkMark=0;
        QString major=this->ui->major->currentText();//获取专业
        cnt="大学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+major+" "+this->ui->stul_Emark->text()
                +" "+this->ui->stul_Pmark->text()+" "+this->ui->stul_Mmark->text()+"\n";
    }
    qDebug("%d",flag);//输出flag
    //判断填写的信息是否合法
    if(name.length()<1||id.length()<9||flag==0||checkMark==0)//信息填写不全
    {
            QMessageBox::warning(this,"错误","信息填写不完整，请重新检查！","确定");
            flag=0;//信息有误
    }
    if(flag==1)//信息无误
    {
            int ret =QMessageBox::question(this,"请确认信息","请确认是否填写无误？","保存","取消");
            if(ret==0)//确认保存
            {
                //修改信息
                writeStu(cnt);
                this->close();
            }
    }
}
void changestu::writeStu(QString cnt)//修改信息
{
    QFile f("stu.txt");
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::critical(this,"错误","文件打开失败！信息未保存！");
            return;
        }

        for(int i=0;i<stu_lines.size();i++)
        {
            QString temp=stu_lines[i].trimmed();//trimmed()用去去除前后的空格
                                                //以防万一
                                                //如果不用应该也没关系
            if(temp==idLine)//那一行需要修改的信息
            {
                QTextStream out(&f);
                out<<cnt;//写入修改后的信息
                continue;
            }
            QTextStream out(&f);
            out<<stu_lines[i];
            out<<"\n";

        }
        QMessageBox::warning(this,"提示","成功修改信息");
        f.close();
}



void changestu::on_stus_clicked()
{
    this->ui->stus_Cmark->setText("0");this->ui->stus_Emark->setText("0");this->ui->stus_Mmark->setText("0");//默认成绩为0
    this->ui->stum_Cmark->clear();this->ui->stum_Emark->clear();this->ui->stum_Gmark->clear();//清空中学生
    this->ui->stum_Hmark->clear();this->ui->stum_Mmark->clear();
    this->ui->stul_Emark->clear();this->ui->stul_Mmark->clear();this->ui->stul_Pmark->clear();//清空大学生
    this->ui->major->setCurrentIndex(0);//初始化专业
    this->ui->stum->setCheckable(false);this->ui->stum->setCheckable(true);//取消按钮
    this->ui->stul->setCheckable(false);this->ui->stul->setCheckable(true);//取消按钮
    this->ui->stus->setFocus();//初始化光标位置
}

void changestu::on_stum_clicked()
{
    this->ui->stum_Cmark->setText("0");this->ui->stum_Emark->setText("0");this->ui->stum_Gmark->setText("0");//默认成绩
    this->ui->stum_Hmark->setText("0");this->ui->stum_Mmark->setText("0");
    this->ui->stus_Cmark->clear();this->ui->stus_Emark->clear();this->ui->stus_Mmark->clear();//清空小学生
    this->ui->stul_Emark->clear();this->ui->stul_Mmark->clear();this->ui->stul_Pmark->clear();
    this->ui->major->setCurrentIndex(0);//初始化专业
    this->ui->stus->setCheckable(false);this->ui->stus->setCheckable(true);//取消按钮
    this->ui->stul->setCheckable(false);this->ui->stul->setCheckable(true);//取消按钮
    this->ui->stum->setFocus();//初始化光标位置
}

void changestu::on_stul_clicked()
{
    this->ui->stul_Emark->setText("0");this->ui->stul_Mmark->setText("0");this->ui->stul_Pmark->setText("0");//默认成绩
    this->ui->stus_Cmark->clear();this->ui->stus_Emark->clear();this->ui->stus_Mmark->clear();
    this->ui->stum_Cmark->clear();this->ui->stum_Emark->clear();this->ui->stum_Gmark->clear();
    this->ui->stum_Hmark->clear();this->ui->stum_Mmark->clear();
    this->ui->stus->setCheckable(false);this->ui->stus->setCheckable(true);//取消按钮
    this->ui->stum->setCheckable(false);this->ui->stum->setCheckable(true);//取消按钮
    this->ui->stul->setFocus();//初始化光标位置
}
