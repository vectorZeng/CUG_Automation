#ifndef HASHMAP_H
#define HASHMAP_H
#include <QString>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QSet>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "tool.h"
/*
 * @auther:wwy
 * @date:2020/12/16
 * @introduction:链表的单个结点
 * @email:773323518@qq.com
 */
class ListNode2{
private:
    /*
     * @introduction:存放英语单词
     */
    QString englishWord;
    /*
     * @introduction:存放英语单词对应的中文释义
     */
    QString chineseMeaning;
public:
    /*
     * @introduction:指向下一个结点
     */
    ListNode2 *next;
    /*
     * @introduction:指向上一个结点
     */
    ListNode2 *pre;
    /*
     * @introduction:构造方法，初始化类变量
     * @pass:ew传入的英文单词，cm传入的中文释义
     * @return:NULL
     */

    QString getEnglishWord() const { return englishWord; } // 添加 const
    QString getChineseMeaning() const { return chineseMeaning; } // 添加 const

    ListNode2(const QString &ew, const QString &cm)
    {
        this->englishWord = ew;
        this->chineseMeaning = cm;
        this->next = nullptr;
        this->pre = nullptr;
    }
    /*
     * @introduction:无参构造方法，初始化类变量
     * @pass:NULL
     * @return:NULL
     */
    ListNode2()
    {
        this->englishWord = nullptr;
        this->chineseMeaning = nullptr;
        this->next = nullptr;
        this->pre = nullptr;
    }
    /*
     * @introduction:设置英语单词
     * @pass:ew传入英文单词
     * @return:NULL
     */
    void setEnglishWord(const QString &ew)
    {
        this->englishWord = ew;
    }
    /*
     * @introduction:得到当前结点的英文单词
     * @pass:NULL
     * @return:当前结点的英文单词
     */
    QString getEnglishWord()
    {
        return this->englishWord;
    }
    /*
     * @introduction:设置当前结点的中文释义
     * @pass:cm传入中文释义
     * @return:NULL
     */
    void setChineseMeaning(const QString &cm)
    {
        this->chineseMeaning = cm;
    }
    /*
     * @introduction:得到当前结点的中文释义
     * @pass:NULL
     * @return:当前结点的中文释义
     */
    QString getChineseMeaning()
    {
        return this->chineseMeaning;
    }

};
/*
 * @auther:wwy
 * @date:2020/12/16
 * @introduction:LinkedList双向链表查找插入删除,用于hashMap解决冲突
 * @email:773323518@qq.com
 */
class LinkedList
{
private:
    /*
     * @introduction:头指针
     */
    ListNode2 *head;
    /*
     * @introduction:链表长度
     */
    int lenth;
public:
    /*
     * @introduction:构造方法
     * @pass:NULL
     * @return:NULL
     */
    LinkedList();
    /*
     * @introduction:头插法
     * @pass:ew英语单词，cm中文释义
     * @return:是否添加成功
     */
    bool addToHead(const QString &ew, const QString &cm);
    /*
     * @introduction:查找单词
     * @pass:ew英语单词
     * @return:中文释义
     */
    QString searchWord(const QString &ew);
    /*
     * @introduction:删除单词
     * @pass:ew英语单词
     * @return:是否删除成功
     */
    bool deleteWord(const QString &ew);
    void lsDebug()
    {
        ListNode2 *p = head->next;
        while (p)
        {
            qDebug() << p->getEnglishWord() << " "<<p->getChineseMeaning();
            p = p->next;
        }
    }
    /*
     * @introduction:获取双链表长度
     * @pass:NULL
     * @return:双链表长度
     */
    int getLength()
    {
        return this->lenth;
    }
    ListNode2* getHead()
    {
        return this->head;
    }
};

/*
 * @auther:wwy
 * @date:2020/12/16
 * @introduction:Hashlist哈希表(djb2),可以实现对字典的查找插入删除
 * @email:773323518@qq.com
 */
class HashMap
{
private:

    /*
     * @introduction:哈希表存储
     */
    LinkedList map[510];
    /*
     * @introduction:哈希表最大范围0~range,range<500
     */
    int range;
    /*
     * @introduction:当前表中单词数
     */
    int length;
    /*
     * @introduction:存放文件路径
     */
    QString filePath;
public:
    ListNode2 getRandomWord();
    /*
     * @introduction:无参构造方法
     * @pass:NULL
     * @return:NULL
     */
    HashMap();
    /*
     * @introduction:构造方法
     * @pass:fp文件路径,rg初始化范围
     * @return:NULL
     */
    HashMap(const QString &fp, int rg);
    /*
     * @introduction:从文件读取数据
     * @pass:fp文件路径
     * @return:NULL
     */
    void fileRead(const QString &fp);
    /*
     * @introduction:将数据写入文件
     * @pass:fn写入文件的路径
     * @return:NULL
     */
    void fileWrite(const QString &fp);
    /*
     * @introduction:查找英语单词并输出它的中文释义
     * @pass:ew要查找的英语单词
     * @return:找到的中文释义
     */
    QString searchWord(const QString &ew);
    /*
     * @introduction:添加单词
     * @pass:待添加的英语单词和中文释义
     * @return:NULL
     */
    bool insertWord(const QString &ew, const QString &cm);
    /*
     * @introduction:删除单词
     * @pass:待删除的英语单词
     * @return:删除是否成功
     */
    bool deleteWord(const QString &ew);
    /*
     * @introduction:djb2哈希函数
     * @pass:ew为英语单词,mod为对hash值取余(防止溢出)
     * @return:取余后的哈希值;
     */
    void hsDebug()
    {
        for(int i = 0; i < this->range; i++)
        {
            if (map[i].getLength()>0)
            {
                qDebug() << i;
                map[i].lsDebug();
            }
        }
        qDebug() << "end";
    }
    /*
     * @introduction:返回当前对应文件路径
     * @pass:NULL
     * @return:返回当前文件对应路径
     */
    QString getFilePath()
    {
        return this->filePath;
    }
    /*
     * @introduction:返回当前表单词数量
     * @pass:NULL
     * @return:单词数量
     */
    int getLength()
    {
        return this->length;
    }
    int static djb2(const QString &ew,int mod);
};

#endif // HASHMAP_H
