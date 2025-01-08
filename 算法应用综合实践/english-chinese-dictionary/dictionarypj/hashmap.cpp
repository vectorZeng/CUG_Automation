#include "hashmap.h"
LinkedList::LinkedList()
{
    this->head = new ListNode2();
    this->lenth = 0;
}

ListNode2 HashMap::getRandomWord()
{
    std::srand(std::time(nullptr)); // 使用当前时间作为随机数种子

    while (true) {
        int index = std::rand() % this->range;
        if (this->map[index].getLength() > 0) {
            ListNode2 *p = this->map[index].getHead()->next;
            int randomIndex = std::rand() % this->map[index].getLength();
            for (int i = 0; i < randomIndex; ++i) {
                p = p->next;
            }
            return *p;
        }
    }
}
bool LinkedList::addToHead(const QString &ew, const QString &cm)
{
    ListNode2 *p = head->next;
    while (p)
    {
        if (p->getEnglishWord().compare(ew) == 0)
        {
            return false;
        }
        p = p->next;
    }
    ListNode2 *now = new ListNode2(ew, cm);
    ListNode2 *temp = head->next;
    if (temp)
    {
        temp->pre = now;
        now->next = temp;
    }
    head->next = now;
    now->pre = head;
    this->lenth++;
    return true;
}

QString LinkedList::searchWord(const QString &ew)
{
    ListNode2 *p = this->head->next;
    while (p)
    {
        if (p->getEnglishWord().compare(ew) == 0)
        {
            return p->getChineseMeaning();
        }
        p = p->next;
    }
    return "no find";
}

bool LinkedList::deleteWord(const QString &ew)
{
    ListNode2 *p = head->next;
    while (p)
    {
        if (p->getEnglishWord().compare(ew) == 0)
        {
            p->pre->next = p->next;
            if (p->next) p->next->pre = p->pre;
            delete p;
            this->lenth --;
            return true;
        }
        p = p->next;
    }
    return false;
}

HashMap::HashMap()
{
    this->filePath = nullptr;
    this->range = 0;
    this->length = 0;
}

HashMap::HashMap(const QString &fp, int rg)
{
    this->filePath = fp;
    this->range = rg;
    this->length = 0;
}

void HashMap::fileRead(const QString &fp)
{
    QFile file(fp);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str = QString::fromLocal8Bit(line);
            QStringList strl = Tool::handleData(str);
            this->map[HashMap::djb2(strl[0],this->range)].addToHead(strl[0], strl[strl.length()-1]);
            this->length ++;
        }
        file.close();
    }
}

void HashMap::fileWrite(const QString &fp)
{
    QFile file(fp);
    file.remove();
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&file);
        for (int i = 0; i < this->range; i++)
        {
            if (map[i].getLength() > 0)
            {
                ListNode2 *p = map[i].getHead()->next;
                while(p)
                {
                    QString qs = p->getEnglishWord() + " " + p->getChineseMeaning();
                    stream << qs << "\n";
                    p = p->next;
                }
            }
        }
        file.close();
    }
}
QString HashMap::searchWord(const QString &ew)
{
    int idx = HashMap::djb2(ew, this->range);
    return this->map[idx].searchWord(ew); //O(n)
}

bool HashMap::insertWord(const QString &ew, const QString &cm)
{
    int idx = HashMap::djb2(ew, this->range);
    if (this->map[idx].addToHead(ew, cm)) //O(1)
    {
        this->length ++;
        return true;
    }
    else
    {
        return false;
    }
}

bool HashMap::deleteWord(const QString &ew)
{
    int idx = HashMap::djb2(ew, this->range);
    if (this->map[idx].deleteWord(ew)) //O(1)
    {
        this->length --;
        return true;
    }
    else
    {
        return false;
    }
}

int HashMap::djb2(const QString &ew,int mod)
{
    int hash = 5381;
    for (int i = 0; i < ew.length(); i++)
    {
        hash = (((hash << 5) + hash) + ew.at(i).unicode()) % mod;
    }
    return hash % mod;
}
