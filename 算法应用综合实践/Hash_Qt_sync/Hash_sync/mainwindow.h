#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemModel>
#include<orderedhashtree.h>
#include<QAbstractButton>
#include<QSystemTrayIcon>
#include<QFileSystemWatcher>
#include<QCloseEvent>
#include"synchronous.h"
using namespace std::chrono;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void init();//用于界面的各种初始化

private slots:
    void on_ButtonSync_clicked();//进行文件同步时按的按钮

    void on_Button_Setting_clicked();//设置按钮，功能跳到设置界面，

    void on_buttonBox_accepted();//确定，在设置界面确定，进行相应的操作

    void on_buttonBox_rejected();//取消操作，会跳第一个界面，即文件夹选择的界面
private:
    //关闭事件，用于程序关闭后，形成托盘状态
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    Synchronous *mySynchronous;//用于处理同步的事情
    //进行托盘处理，这样就这可以进行实时同步等功能
    QSystemTrayIcon *systemtray;
    QAction *minAction;
    QAction *maxAction;
    QAction *resstoreAction;
    QAction *quitAction;
    QMenu *pContextMenu;

    //设置方面的，用于设置
    QButtonGroup* ButtonGroupPre_Mode;
    QButtonGroup* ButtonGroup_Way ;
    QButtonGroup* ButtonGroup;

    //用于定时器，记录定时器
    int Timetag;
};

#endif // MAINWINDOW_H
