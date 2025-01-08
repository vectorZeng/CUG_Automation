#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//矩阵定义
#define M 3
#define N 3

//单个结点
typedef struct node{
    int matrix[M][N];
    int hx;
    int gx;
    int fx;
    struct node* next;
    struct node* hide_pre;  //
}Node;
typedef node* nodePtr;

//OPEN、CLOSE链表
typedef struct{
    nodePtr head;
    nodePtr tail;
}LList;
typedef LList* LListPtr;

//计算hx的启发式函数
int cal_hx(nodePtr edge);


#endif // HEAD_H
