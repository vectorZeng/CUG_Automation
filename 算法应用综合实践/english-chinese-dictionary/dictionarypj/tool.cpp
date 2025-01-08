#include "tool.h"

QStringList Tool::handleData(QString data)
{   if (data.at(data.length()-1) == '\n')
    {
        data.chop(1);
    }
    return data.split(" ");
}

int Tool::trieIndex(QChar c)
{
    if (c >= 'a' && c <= 'z') return c.unicode()-'a';
    if (c == '.') return 26;
    if (c == '/') return 27;
    if (c == '-') return 28;
    if (c == '\'') return 29;
    return -1;
}
