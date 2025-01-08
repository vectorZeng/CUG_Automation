#include "eightpuzzle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eightPuzzle w;
    w.show();
    return a.exec();
}
