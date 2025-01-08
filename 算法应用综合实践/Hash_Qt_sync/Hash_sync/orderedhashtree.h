#ifndef ORDEREDHASHTREE_H
#define ORDEREDHASHTREE_H
#include<QString>
#include<QByteArray>
#include<QCryptographicHash>
#include<QStringList>
/*用五元组<p, h, Parent, FistChild, NextSibling>表示。其中，p表示该
节点对应的文件相对路径，h表示该节点存储的Hash值，Parent, FistChild和NextSibling分别
代表该节点在OHT中的父节点、头子孙节点和后继兄弟节点。*/
struct HashNode
{
    QString path;           //该节点对应的文件相对路径
    QByteArray h;                //Hash值
    HashNode *Parent;       //代表该节点在OHT中的父节点
    HashNode *FistChild;    //头子孙节点
    HashNode *NextSibling;  //后继兄弟节点
    HashNode()
    {

        Parent=NULL;
        FistChild=NULL;
        NextSibling=NULL;
    }

    //重载运算符
    bool operator ==(HashNode *other)
    {
        if(path==other->path&&h==other->h&&Parent==other->Parent
                &&FistChild==other->FistChild&&NextSibling==other->NextSibling)
            return true;
        return false;
    }

};

class Ordered_Hash_Tree
{
public:
    Ordered_Hash_Tree(QString path);
    ~Ordered_Hash_Tree();
    //采取递归的方法做
    HashNode *Build_OHT(QString absPath,QString Relativepath);
    void sortTree(HashNode *rn,HashNode *node);//对树进行排序
    void clear(HashNode *node);
    void ResetTree(QString path);//重新修改树
    void Rebuild();//再次建树，不过对原来的目录
    HashNode *getRN();//得到根节点

    QString abspath;//记录绝对路径
    QStringList paths;//记录文件夹下所有目录或者文件的路径，是绝对路径，方便文件监视器
private:
    HashNode *RN;       //有序哈希树的根节点
};

#endif // ORDEREDHASHTREE_H
