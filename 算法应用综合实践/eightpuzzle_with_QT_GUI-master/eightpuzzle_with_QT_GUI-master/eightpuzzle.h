#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QElapsedTimer>
#include <iostream>
#include "head.h"
#include <QMainWindow>
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class eightPuzzle; }
QT_END_NAMESPACE

class eightPuzzle : public QMainWindow
{
    Q_OBJECT

public:
    eightPuzzle(QWidget *parent = nullptr);
    ~eightPuzzle();

    about *new_about;
    //初始化问题状态
    nodePtr init();

    //启发式函数
    int cal_hx(nodePtr node){
        int ans = 0;
        for(int i = 0 ; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(node->matrix[i][j] != des_matrix[i][j]) ans++;
            }
        }
        return ans;
    }

    //检查最终状态是否正确
    int check_des(LListPtr list);

    //初始化OPEN表
    LListPtr initOpenList();

    //取OPEN表的第一个节点
    nodePtr get_open_first(LListPtr open);

    //初始化CLOSE表
    LListPtr initCloseList();

    //比较单个结点
    int compare_node(nodePtr first, nodePtr second);

    //遍历CLOSE表以查找是否走过
    //1-走过 0-未走过
    int travel_close(LListPtr close, nodePtr expand_node);

    //寻找0所在的格
    int findZero(nodePtr node);

    //将节点加到open表里
    void add_to_open(LListPtr open, nodePtr node);

    //将节点加入close表，结束该节点的拓展流程
    void add_to_close(LListPtr closed, nodePtr node);

    //根据dir = 1 2 3 4进行上 下 左 右填充
    void step(int x, int y, int dir, nodePtr node, LListPtr open, LListPtr closed);

    //根据0的位置进行移动并进行试探
    //判重 如果已有则判断步数哪个更优 不存在则加入open表
    void have_a_try(int x, int y, nodePtr node, LListPtr open, LListPtr closed);

    //拓展该节点的下一个状态
    void expand_next(LListPtr open, LListPtr closed, nodePtr to_expand);

    //检查OPEN表的第一个节点是否是目标
    int check_now(nodePtr node);

    //入口函数，维护open close表
    nodePtr solve();

    //循环输出函数
    int recursion_output(nodePtr node);

    //找到对应Label
    QLabel *find_label(int i);

    void free_list(LListPtr list);
private slots:
    //RUN
    void on_runButton_clicked();
    //about
    void on_pushButton_clicked();
    //记录
    void on_pushButton_2_clicked();

private:
    int des_matrix[M][N];
    LListPtr open = NULL, close = NULL;
    nodePtr first = NULL;
    Ui::eightPuzzle *ui;
};
#endif // EIGHTPUZZLE_H
