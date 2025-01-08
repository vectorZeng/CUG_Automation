#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDesktopServices>
#include<QDir>
#include<QFile>
#include<QDebug>
#include<QCryptographicHash>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


   ui->setupUi(this);
   this->init();
   this->setWindowTitle("QTSync");
}

MainWindow::~MainWindow()
{
    if(mySynchronous!=NULL)
    delete mySynchronous;
    delete ui;

}
//初始化软件
void MainWindow::init()
{
    //设置浏览文件的模型，有个个模型都要展示，一个是源文件，一个是目标文件
    QFileSystemModel* model = new QFileSystemModel();
    model->setReadOnly(false);      //设置为能读能写
    model->setRootPath("E:/");
    ui->treeView->setModel(model);
    ui->treeView->setCurrentIndex(model->index("E:/"));
    ui->treeView->setSortingEnabled(true);
    ui->treeView->header()->setStretchLastSection(true);//当 QTreeView 的宽度大于所有列宽之和时，最后一列的宽度自动扩展以充满最后的边界
    ui->treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    ui->treeView->header()->setSortIndicatorShown(true);
    ui->treeView->header()->setSectionsClickable(true);
    //
    QFileSystemModel* models = new QFileSystemModel();
    models->setReadOnly(false);      //设置为能读能写
    models->setRootPath("E:/");
    ui->treeViews->setModel(models);
    ui->treeViews->setCurrentIndex(models->index("E:/"));
    ui->treeViews->setSortingEnabled(true);
    ui->treeViews->header()->setStretchLastSection(true);//当 QTreeView 的宽度大于所有列宽之和时，最后一列的宽度自动扩展以充满最后的边界
    ui->treeViews->header()->setSortIndicator(0, Qt::AscendingOrder);
    ui->treeViews->header()->setSortIndicatorShown(true);
    ui->treeViews->header()->setSectionsClickable(true);
    this->setWindowTitle("File System Model");

    //进行托盘，下面是托盘后的一些菜单操作
    QIcon icon(":/new/prefix1/image/1.ico");
    systemtray=new QSystemTrayIcon(this);
    systemtray->setIcon(icon);
    systemtray->setToolTip("QTSync");
    minAction=new QAction("Minimum Window",this);
    connect(minAction, SIGNAL(triggered()), this, SLOT(hide()));
    maxAction=new QAction("Maximum Window",this);
    connect(maxAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
    resstoreAction=new QAction("Restore Window",this);
    connect(resstoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    quitAction=new QAction("Quit Application",this);
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    pContextMenu=new QMenu(this);
    pContextMenu->addAction(minAction);
    pContextMenu->addAction(maxAction);
    pContextMenu->addAction(resstoreAction);
    pContextMenu->addSeparator();
    pContextMenu->addAction(quitAction);
    systemtray->setContextMenu(pContextMenu);
    systemtray->show();



//设置文本条上显示选中的路径
    connect(ui->treeView,QTreeView::clicked,
            [=](QModelIndex index)

    {
             QString str= model->filePath(index);
            // qDebug()<<model->filePath(index);
             ui->lineEdit->setText(str);
    }

          );


    connect(ui->treeViews,QTreeView::clicked,
            [=](QModelIndex index)

    {
        QString str= models->filePath(index);
       // qDebug()<<models->filePath(index);
        ui->lineEdits->setText(str);
    }

          );

     //设置单选框，其中单选框为冲突处理需要解决的方式
     ButtonGroupPre_Mode = new QButtonGroup(this);
     ButtonGroupPre_Mode->addButton(ui->checkBox,1);//左
     ButtonGroupPre_Mode->addButton(ui->checkBox_2,2);//右
     ButtonGroupPre_Mode->addButton(ui->checkBox_3,3);//新
     ui->checkBox->setChecked(true);
     //为单向同步和双向同步的方式
     ButtonGroup_Way = new QButtonGroup(this);
     ButtonGroup_Way->addButton(ui->checkBox_4,4);//单向
     ButtonGroup_Way->addButton(ui->checkBox_5,5);//双向
     ui->checkBox_4->setChecked(true);

     ButtonGroup = new QButtonGroup(this);
     ButtonGroup->addButton(ui->radioButton,1);
     ButtonGroup->addButton(ui->radioButton_2,2);
     ui->radioButton_2->setChecked(true);
}

//开始进行同步
void MainWindow::on_ButtonSync_clicked()
{
    QString p1=ui->lineEdit->text();
    QString p2=ui->lineEdits->text();
    if(mySynchronous==NULL)
        mySynchronous=new Synchronous(p1,p2);
    else
    {
        if(mySynchronous->isDifferent(p1,p2))
        {
            this->mySynchronous->Reset(p1,p2);
        }
    }
    mySynchronous->solve();
    QMessageBox::information(this,"提示","同步成功");
    //qDebug()<<"同步成功";
}

//进入设置界面
void MainWindow::on_Button_Setting_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//设置好了，确定后的进行的操作
void MainWindow::on_buttonBox_accepted()
{
   // qDebug()<<ButtonGroupPre_Mode->checkedId();
   // qDebug()<<ButtonGroup_Way->checkedId();
   // qDebug()<<ui->comboBox->currentIndex();
    switch (ButtonGroupPre_Mode->checkedId()) //发生文件冲突，优先的选择
    {
    case 1:
        mySynchronous->Pre_mode=Left;
        break;
    case 2:
        mySynchronous->Pre_mode=Right;
        break;
    case 3:
        mySynchronous->Pre_mode=New;
        break;
    default:
        break;
    }

    switch (ButtonGroup_Way->checkedId()) //同步的方向
    {
    case 5:
        mySynchronous->way=one_way;
        break;
    case 6:
        mySynchronous->way=two_way;
        break;
    default:
        break;
    }

    switch (ButtonGroup->checkedId()) //是否是自动
    {
    case 1:
        mySynchronous->Automatic=false;
        break;
    case 2:
        mySynchronous->Automatic=true;
        mySynchronous->killTimer(Timetag);
        break;
    default:
        break;
    }

    //非自动，就是定时处理
    if(mySynchronous->Automatic==false)
    {
        switch (ui->comboBox->currentIndex())
        {
        case 0:
          Timetag= mySynchronous->startTimer(minutes(10));
            break;
        case 1:
         Timetag=  mySynchronous->startTimer(minutes(30));
            break;
        case 2:
         Timetag=  mySynchronous->startTimer(hours(1));
            break;
        case 3:
          Timetag= mySynchronous->startTimer(hours(12));
            break;
        case 4:
         Timetag=  mySynchronous->startTimer(hours(24));
            break;
        default:
            break;
        }
    }
    QMessageBox::information(this,"提示","设置成功");
}

//取消就返回同步界面
void MainWindow::on_buttonBox_rejected()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    hide();
    systemtray->showMessage("Tips", "The program is running behind!");
    event->ignore();
}

