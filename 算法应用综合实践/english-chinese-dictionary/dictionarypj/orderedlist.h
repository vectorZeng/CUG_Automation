#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <QFile>
#include <QDebug>
#include "tool.h"
class Tool;
/*
 * @auther:wwy
 * @date:2020/12/14
 * @introduction:OrderedList的单个结点，用于封装单词和对应的中文释义
 * @email:773323518@qq.com
 */
class ListNode
{
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
     * @introduction:构造方法，初始化类变量
     * @pass:ew传入的英文单词，cm传入的中文释义
     * @return:NULL
     */
    ListNode(const QString &ew, const QString &cm)
    {
        this->englishWord = ew;
        this->chineseMeaning = cm;
    }
    /*
     * @introduction:无参构造方法，初始化类变量
     * @pass:NULL
     * @return:NULL
     */
    ListNode()
    {
        this->englishWord = nullptr;
        this->chineseMeaning = nullptr;
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
    QString getEnglishWord() const
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


    QString getChineseMeaning() const
    {
        return this->chineseMeaning;
    }

};
/*
 * @auther:wwy
 * @date:2020/12/14
 * @introduction:OrderedList有序表,可以实现对字典的查找插入删除
 * @email:773323518@qq.com
 */
class OrderedList
{
private:
    /*
     * @introduction:存放单词数据
     */
    ListNode data[2000];
    /*
     * @introduction:存放文件路径
     */
    QString filePath;
    /*
     * @introduction:线性表长度
     */
    int length;
public:
 /*
     * @introduction: 获取指定数量的随机单词
     * @pass: count 要获取的单词数量
     * @return: 包含随机单词的 QList
     */
    QList<ListNode> getRandomWords(int count)
    {
        QList<ListNode> randomWords;
        if (count > this->length) {
            count = this->length; // 如果请求的单词数量超过现有单词数量，则调整为最大数量
        }

        std::srand(std::time(nullptr)); // 使用当前时间作为随机数种子
        QSet<int> indices; // 用于存储已经选择的索引，确保不重复

        while (indices.size() < count) {
            int index = std::rand() % this->length;
            if (!indices.contains(index)) {
                indices.insert(index);
                randomWords.append(this->data[index]);
            }
        }

        return randomWords;
    }
    /*
     * @introduction:无参构造方法
     * @pass:NULL
     * @return:NULL
     */
    OrderedList();
    /*
     * @introduction:构造方法
     * @pass:fp读取文件的路径
     * @return:NULL
     */
    OrderedList(const QString &fp);
    /*
     * @introduction:读取文件数据到data数组
     * @pass:fn读取文件的路径
     * @return:NULL
     */
    void fileRead(const QString &fp);
    /*
     * @introduction:将data数组数据写入文件
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
     * @introduction:返回线性表长度
     * @pass:NULL
     * @return:线性表长度
     */
    int getLength()
    {
        return this->length;
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
    void olDebug(){

        for(int i = 0; i < this->length; i++){
            qDebug() << data[i].getEnglishWord()<<data[i].getChineseMeaning();
        }
        qDebug() <<"end";
    }

    /*
     * @introduction:交换两个ListNode的值
     * @pass:l1,l2为待交换的数据
     * @return:NULL
     */
    static void swapln(ListNode &l1, ListNode &l2);

    /*
     * @introduction:获取data数组
     * @pass:NULL
     * @return:返回data数组
     */
    const ListNode* getData() const
    {
        return this->data;
    }
};

#endif // ORDEREDLIST_H
