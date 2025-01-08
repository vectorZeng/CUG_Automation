#include "trietree.h"

// 无参构造函数，初始化根节点、文件路径和单词数量
TrieTree::TrieTree()
{
   this->root = new TreeNode; // 创建根节点
   this->filePath = nullptr;  // 初始化文件路径为空
   this->length = 0;          // 初始化单词数量为0
}

// 带文件路径参数的构造函数，初始化根节点、文件路径和单词数量
TrieTree::TrieTree(const QString &fp)
{
    this->root = new TreeNode; // 创建根节点
    this->filePath = fp;       // 设置文件路径
    this->length = 0;          // 初始化单词数量为0
}

// 从文件读取数据并插入到Trie树中
void TrieTree::fileRead(const QString &fp)
{
    QFile file(fp); // 打开文件
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine(); // 读取文件中的每一行
            QString str = QString::fromLocal8Bit(line); // 将每一行转换为QString
            QStringList strl = Tool::handleData(str); // 处理数据，分割成单词和释义
            if(!this->insertWord(strl[0], strl[strl.length()-1])) qDebug()<<strl[0]; // 插入单词和释义
        }
        file.close(); // 关闭文件
    }
}

// 将Trie树中的数据写入文件
void TrieTree::fileWrite(const QString &fp)
{
    QFile file(fp);
    file.remove(); // 删除旧文件
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&file);
        QQueue<TreeNode*> q; // 定义队列用于广度优先搜索
        q.enqueue(this->root); // 将根节点加入队列
        while(!q.isEmpty())
        {
            TreeNode *currentNode = q.dequeue(); // 取出队列中的节点
            if (currentNode->isExistence())
            {
                QString qs = currentNode->getEnglishWord() + " " + currentNode->getChineseMeaning();
                stream << qs << "\n"; // 将单词和释义写入文件
            }
            for(int i = 0; i < 30; i++)
            {
                if(currentNode->next[i])
                {
                    q.enqueue(currentNode->next[i]); // 将子节点加入队列
                }
            }
        }
        file.close(); // 关闭文件
    }
}

// 插入单词到Trie树中
bool TrieTree::insertWord(const QString &ew, const QString &cm)
{
    TreeNode *currentNode = this->root; // 从根节点开始
    for (int i = 0; i < ew.length(); i++)
    {
        QChar t = ew.at(i);
        if (Tool::trieIndex(t) == -1) return false; // 非法字符
        if (!currentNode->next[Tool::trieIndex(t)])
        {
            currentNode->next[Tool::trieIndex(t)] = new TreeNode; // 创建新节点
        }
        currentNode = currentNode->next[Tool::trieIndex(t)]; // 移动到子节点
    }
    if (currentNode->isExistence())
        return false; // 单词已存在
    else
    {
        currentNode->setExistence(true); // 标记为单词结尾
        currentNode->setEnglishWord(ew); // 设置单词
        currentNode->setChineseMeaning(cm); // 设置释义
        this->length ++; // 单词数量加1
        return true;
    }
}

// 查找单词在Trie树中的释义
QString TrieTree::searchWord(const QString &ew)
{
    TreeNode *currentNode = this->root; // 从根节点开始
    for (int i = 0; i < ew.length(); i++)
    {
        QChar t = ew.at(i);
        if (Tool::trieIndex(t) == -1 || !currentNode->next[Tool::trieIndex(t)])
        {
            return "no find"; // 未找到单词
        }
        currentNode = currentNode->next[Tool::trieIndex(t)]; // 移动到子节点
    }
    return currentNode->getChineseMeaning(); // 返回释义
}

// 删除Trie树中的单词
bool TrieTree::deleteWord(const QString &ew)
{
    TreeNode *currentNode = this->root; // 从根节点开始
    for (int i = 0; i < ew.length(); i++)
    {
        QChar t = ew.at(i);
        if (Tool::trieIndex(t) == -1 || !currentNode->next[Tool::trieIndex(t)])
        {
            return false; // 未找到单词
        }
        currentNode = currentNode->next[Tool::trieIndex(t)]; // 移动到子节点
    }
    currentNode->setExistence(false); // 标记为非单词结尾
    currentNode->setEnglishWord("no find"); // 清空单词
    currentNode->setChineseMeaning("no find"); // 清空释义
    this->length--; // 单词数量减1
    return true;
}
