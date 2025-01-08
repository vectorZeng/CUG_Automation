#ifndef TRIETREE_H
#define TRIETREE_H
#include <QString>
#include <QFile>
#include "tool.h"
#include <QQueue>
/*
 * @auther:wwy
 * @date:2020/12/17
 * @introduction:字典树的单个结点
 * @email:773323518@qq.com
 */
class TreeNode
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
    /*
     * @introduction:标记当前结点有无单词存在
     */
    bool existence;
public:
    /*
     * @introduction:孩子结点指针
     */
    TreeNode *next[30];
    TreeNode()
    {
        this->englishWord = "no find";
        this->chineseMeaning = "no find";
        this->existence = false;
        for(int i = 0; i < 30; i++)
        {
            this->next[i] = nullptr;
        }
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
    /*
     * @introduction:判断当前结点是否存在
     * @pass:NULL
     * @return:当前结点的存在情况
     */
    bool isExistence()
    {
        return this->existence;
    }
    /*
     * @introduction:设置当前结点的存在情况
     * @pass:当前结点的存在情况
     * @return:NULL
     */
    void setExistence(bool e)
    {
        this->existence = e;
    }
};
/*
 * @auther:wwy
 * @date:2020/12/17
 * @introduction:字典树数据结构
 * @email:773323518@qq.com
 */
class TrieTree
{
private:
    /*
     * @introduction:根结点
     */
    TreeNode *root;
    /*
     * @introduction:文件路径
     */
    QString filePath;
    /*
     * @introduction:当前单词总数
     */
    int length;
public:


    /*
     * @introduction:无参构造方法
     * @pass:NULL
     * @return:NULL
     */
    TrieTree();


    /*
     * @introduction:构造方法
     * @pass:fp读取文件的路径
     * @return:NULL
     */
    TrieTree(const QString &fp);


    /*
     * @introduction:添加单词
     * @pass:待添加的英语单词和中文释义
     * @return:NULL
     */
    bool insertWord(const QString &ew, const QString &cm);

    /*
     * @introduction:查找英语单词并输出它的中文释义
     * @pass:ew要查找的英语单词
     * @return:找到的中文释义
     */
    QString searchWord(const QString &ew);

    /*
     * @introduction:删除单词
     * @pass:待删除的英语单词
     * @return:删除是否成功
     */
    bool deleteWord(const QString &ew);

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
};

#endif // TRIETREE_H
