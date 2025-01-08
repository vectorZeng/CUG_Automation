#include "form3.h"
#include "ui_form3.h"

// 构造函数，初始化UI和单词总数
Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this); // 设置UI
    this->sumn = 0;    // 初始化单词总数为0
}

// 析构函数，释放UI资源
Form3::~Form3()
{
    delete ui;
}

// 初始化工作，读取文件数据到Trie树中
void Form3::work()
{
    for (int i = 0; i < 26; i++) {
        QString str = QString("noorderdata/%1.txt").arg(char('a' + i)); // 构造文件路径
        this->word[i] = TrieTree(str); // 初始化Trie树
        this->word[i].fileRead(str);   // 从文件读取数据
        this->sumn += this->word[i].getLength(); // 累加单词总数
    }
    ui->label_12->setText(QString("%1").arg(this->sumn)); // 更新UI上的单词总数显示
}

// 返回按钮点击事件处理，返回主窗口
void Form3::on_pushButton_4_clicked()
{
    Widget *w = new Widget; // 创建主窗口对象
    w->show();              // 显示主窗口
    this->close();          // 关闭当前窗口
}

// 查找按钮点击事件处理，查找单词
void Form3::on_pushButton_clicked()
{
    QString searchWord = ui->lineEdit->text(); // 获取输入的单词
    if (searchWord == "") {
        ui->label_3->setText("LineEdit is empty"); // 输入为空时提示
        return;
    }
    char headsw = searchWord.at(0).unicode(); // 获取单词首字母
    if (headsw >= 'a' && headsw <= 'z') {
        ui->label_3->setText(this->word[headsw - 'a'].searchWord(searchWord)); // 查找单词并显示释义
    } else {
        ui->label_3->setText("illegal word"); // 非法单词提示
        return;
    }
}

// 添加按钮点击事件处理，添加单词
void Form3::on_pushButton_2_clicked()
{
    QString ew = ui->lineEdit_2->text(); // 获取输入的英文单词
    QString cm = ui->lineEdit_4->text(); // 获取输入的中文释义
    if (ew == "" || cm == "") {
        ui->label_4->setText("LineEdit is empty"); // 输入为空时提示
        return;
    }
    char headew = ew.at(0).unicode(); // 获取单词首字母
    if (headew >= 'a' && headew <= 'z') {
        if (word[headew - 'a'].insertWord(ew, cm)) { // 插入单词
            this->word[headew - 'a'].fileWrite(this->word[headew - 'a'].getFilePath()); // 写入文件
            this->sumn++; // 单词总数加1
            ui->label_12->setText(QString("%1").arg(this->sumn)); // 更新UI上的单词总数显示
            QString ifm = "successfully add \"" + ew + "\"";
            ui->label_4->setText(ifm); // 显示成功添加信息
        } else {
            ui->label_4->setText("the word is already existent"); // 单词已存在提示
        }
    } else {
        ui->label_4->setText("illegal word"); // 非法单词提示
    }
}

// 删除按钮点击事件处理，删除单词
void Form3::on_pushButton_3_clicked()
{
    QString ew = ui->lineEdit_3->text(); // 获取输入的英文单词
    if (ew == "") {
        ui->label_6->setText("LineEdit is empty"); // 输入为空时提示
        return;
    }
    char headew = ew.at(0).unicode(); // 获取单词首字母
    if (headew >= 'a' && headew <= 'z') {
        if (word[headew - 'a'].deleteWord(ew)) { // 删除单词
            word[headew - 'a'].fileWrite(this->word[headew - 'a'].getFilePath()); // 写入文件
            this->sumn--; // 单词总数减1
            ui->label_12->setText(QString("%1").arg(this->sumn)); // 更新UI上的单词总数显示
            QString ifm = "successfully delete \"" + ew + "\"";
            ui->label_6->setText(ifm); // 显示成功删除信息
        } else {
            ui->label_6->setText("the word isn't existent"); // 单词不存在提示
        }
    } else {
        ui->label_6->setText("illegal word"); // 非法单词提示
    }
}
