#ifndef SYNCHRONOUS_H
#define SYNCHRONOUS_H
#include"orderedhashtree.h"
#include<QList>
#include<QFileSystemWatcher>
#include<QObject>
#include<QPair>
#include<QFileInfo>
//文件处理的三种方式
enum Mode
{
  Add,Remove,Update
};

//文件同步的两种方向：单向和双向
enum Sync_Way
{
    one_way,two_way
};

//文件同步的三种方式：左侧优、右侧优先、新文件优先
enum Sync_Pre_Mode
{
  Left,Right,New
};


//将原来的文件和新的文件进行同步
struct FileNode
{
    QString op_Path;//原来的文件路径
    Mode    sloveMode;
    FileNode() {}
};


class Synchronous :public QObject
{
public:
    //构造函数
    Synchronous(QString ohtpath,QString ohtspath,QObject *parent = nullptr);
    ~Synchronous();//析构函数
    //比较哈希树，得出两边的差异，根据论文上的算法
    QList<FileNode> Compare_OHT(HashNode *subOHT,HashNode *subOHTs);
    void Add_Sub_OHT(HashNode *subOHT,QList<FileNode>&l);
    void Remove_Sub_OHT(HashNode *subOHT,QList<FileNode>&l);
    void Update_Sub_OHT(HashNode *subOHT,HashNode *subOHTs,QList<FileNode>&l);

    //第一次同步
    void solve();

    //用于判断，第二次同步的是否是相同的项目
    bool isDifferent(QString p1, QString p2);
    //重新设置，用于对新的文件夹进行同步
    void Reset(QString ohtpath, QString ohtspath);

    Sync_Way way;           //同步方向,是单向还是双向
    Sync_Pre_Mode Pre_mode; //同步冲突优先的方式
    bool Automatic;         //是否自动进行同步
protected:
    //定时器
    void timerEvent(QTimerEvent *event);
    //处理两边同步，会调用Creat,Delete,Modify
    void solvefile(Ordered_Hash_Tree *oht, Ordered_Hash_Tree *ohts);
    //对树进行操作，使两边同步，利用了比对后文件的差异集合l，操作分别为创建、删除、更新
    void Creat(Ordered_Hash_Tree *Tree,FileNode f);
    void Delete(Ordered_Hash_Tree *Tree,FileNode f);
    void Modify(Ordered_Hash_Tree *oht,Ordered_Hash_Tree *ohts,FileNode f);

private:
    Ordered_Hash_Tree *oht;     //两个哈希树
    Ordered_Hash_Tree *ohts;
    QList<FileNode>l;           //文件不同的集合，用链表表示
    QFileSystemWatcher *ohtWatcher;     //文件监视器，用于监视文件两边有没有发生文件变化
    QFileSystemWatcher *ohtsWatcher;
    QMap<QString,QTime>  ohtmodifications;  //记录在规定时间内文件的变化
    QMap<QString,QTime> ohtsmodifications;
    QString ohtpath;            //开始两个文件夹或者磁盘的路径
    QString ohtspath;

};

#endif // SYNCHRONOUS_H
