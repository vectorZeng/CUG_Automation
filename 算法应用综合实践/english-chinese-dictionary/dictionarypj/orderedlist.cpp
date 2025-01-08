#include "orderedlist.h"
OrderedList::OrderedList()
{
    this->filePath = nullptr;
    this->length = 0;
}
OrderedList::OrderedList(const QString &fp)
{
    this->filePath = fp;
    this->length = 0;
}
void OrderedList::fileRead(const QString &fp)
{
    QFile file(fp);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str = QString::fromLocal8Bit(line);
            QStringList strl = Tool::handleData(str);
            this->data[this->length].setEnglishWord(strl[0]);
            this->data[this->length].setChineseMeaning(strl[strl.length()-1]);
            for (int i = this->length; i >0; i--)   //插排O(n) ~ O(n^2) 由于原始数据接近有序，所以为O(n)
            {
                if (this->data[i].getEnglishWord().compare(this->data[i-1].getEnglishWord()) < 0)
                {
                    OrderedList::swapln(this->data[i],this->data[i-1]);
                }
                else break;
            }
            this->length ++;
        }
        file.close();
      }
}
void OrderedList::fileWrite(const QString &fp)
{
    QFile file(fp);
    file.remove();
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&file);
        for (int i = 0; i < this->length; i++)
        {
            QString qs = data[i].getEnglishWord() + " " +data[i].getChineseMeaning();
            stream << qs << "\n";
        }
        file.close();
    }
}

QString OrderedList::searchWord(const QString &ew)
{
    ListNode res; // 声明一个 ListNode 对象 res，用于存储找到的结果
    int l = 0; // 初始化左边界 l 为 0
    int r = this->length - 1; // 初始化右边界 r 为 length - 1，即数组的最后一个索引
    while (l <= r) // 二分查找 O(logn)
    {
        int mid = (l + r) >> 1; // 计算中间索引 mid，使用右移操作符 >> 1 相当于除以 2
        if (this->data[mid].getEnglishWord().compare(ew) >= 0) // 比较中间元素的英文单词与目标单词 ew
        {
            res = this->data[mid]; // 如果中间元素的英文单词大于或等于 ew，则将 res 设置为中间元素
            r = mid - 1; // 将右边界 r 移动到 mid - 1
        }
        else
            l = mid + 1; // 否则，将左边界 l 移动到 mid + 1
    }
    if (res.getEnglishWord().compare(ew) == 0) // 检查 res 中的英文单词是否与 ew 相等
        return res.getChineseMeaning(); // 如果相等，返回 res 中的中文释义
    else
        return "no find"; // 否则，返回 "no find" 表示没有找到对应的英文单词
}

bool OrderedList::insertWord(const QString &ew,const QString &cm)
{
    int leftBound = this->length; //左界
    int l = 0;
    int r  = this->length - 1;
    while (l <= r)  //二分查找到该单词在线性表中的位置O(logn)
    {
        int mid = (l+r) >> 1;
        if(this->data[mid].getEnglishWord().compare(ew) >= 0)
        {
            leftBound = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (this->data[leftBound].getEnglishWord().compare(ew) == 0) //如果相等就说明已经存在这个单词，插入失败
    {
        return false;
    }
    for (int i = this->length; i > leftBound; i--)  //线性插入O(n)
    {
        OrderedList::swapln(this->data[i],this->data[i-1]);
    }
    this->length ++;
    this->data[leftBound].setEnglishWord(ew);
    this->data[leftBound].setChineseMeaning(cm);
    return true;
}

bool OrderedList:: deleteWord(const QString &ew)
{
    int leftBound = this->length; //左界
    int l = 0;
    int r  = this->length - 1;
    while (l <= r) //二分查找到该单词在线性表中的位置O(logn)
    {
        int mid = (l+r) >> 1;
        if(this->data[mid].getEnglishWord().compare(ew) >= 0)
        {
            leftBound = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (this->data[leftBound].getEnglishWord().compare(ew) != 0) //如果不相等就说明没有这个单词，插入失败
    {
        return false;
    }
    for (int i = leftBound; i < this->length - 1; i++)  //线性插入O(n)
    {
        OrderedList::swapln(this->data[i],this->data[i + 1]);
    }
    this->length --;
    return true;
}

void OrderedList::swapln(ListNode &l1, ListNode &l2){
    QString tempew = l2.getEnglishWord();
    QString tempcm = l2.getChineseMeaning();
    l2.setEnglishWord(l1.getEnglishWord());
    l2.setChineseMeaning(l1.getChineseMeaning());
    l1.setEnglishWord(tempew);
    l1.setChineseMeaning(tempcm);
}
