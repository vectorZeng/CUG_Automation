//#include "head.h"
#include "eightpuzzle.h"
#include "ui_eightpuzzle.h"
extern int des_matrix[M][N];
//初始化函数
nodePtr eightPuzzle::init()  {
    int Input[9] = {0};//接受输入
    nodePtr head = (nodePtr)malloc(sizeof(node));
    int signal = 1;//标志
    if(head != NULL) {
        //内存分配成功
        signal = 0;
        for(int i = 0 ; i < 9; i++) Input[i] = 0;   //清零
        //读入数据
        head->matrix[0][0] = ui->init1->text().toInt();
        head->matrix[0][1] = ui->init2->text().toInt();
        head->matrix[0][2] = ui->init3->text().toInt();
        head->matrix[1][0] = ui->init4->text().toInt();
        head->matrix[1][1] = ui->init5->text().toInt();
        head->matrix[1][2] = ui->init6->text().toInt();
        head->matrix[2][0] = ui->init7->text().toInt();
        head->matrix[2][1] = ui->init8->text().toInt();
        head->matrix[2][2] = ui->init9->text().toInt();

        //检查输入数据
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                Input[head->matrix[i][j]]++;      //1表示0-8有数字输入
            }
        }
        //
        for(int i = 0; i < 9; i++) {
            //有未输入OR输入数字大于一次
            if(!Input[i]||Input[i] > 1) signal = 1;               //标志置1
        }

        if(signal) {
            //弹窗告知
            QMessageBox::information(NULL, "Waring", "请检查初始输入!错误代码-I01", QMessageBox::Yes, QMessageBox::Yes);
            return NULL;
        }
        //内参初始化
        head->gx = 0;
        head->hx = cal_hx(head);//计算hx
        head->fx = head->gx + head->hx;
        head->next = NULL;
        head->hide_pre = NULL;

    }else {
        //printf("警告！内存分配失败，请重试！错误代码-M01\n");
         QMessageBox::warning(NULL, "warning", "警告！内存分配失败，请重试!错误代码-M01", QMessageBox::Yes, QMessageBox::Yes);
        return NULL;
    }
    return head;
}

//检查最终输入函数
int eightPuzzle::check_des(LListPtr list) {
    int sum1 = 0, sum2 = 0, signal = 0;
    int arr1[9] = {0}, arr2[9] = {0};
    int Output[9]={0};
    for(int i = 0 ; i < M; i++) {
        for(int j = 0; j < N; j++) {
            //arr1---最终要形成的矩阵
            //arr2---最初输入的矩阵
            arr1[i*3 + j] = des_matrix[i][j];
            arr2[i*3 + j] = list->head->matrix[i][j];
        }
    }
    //进行逆序对的判断
    //空格以0代替
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < i; j++) {
            if(arr1[i] && (arr1[i] < arr1[j])) sum1++;
            if(arr2[i] && (arr2[i] < arr2[j])) sum2++;
        }
    }
    //检查最终输入状态是否有误
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            Output[des_matrix[i][j]]++;
        }
    }
    for(int i = 0; i < 9; i++) {
        if(!Output[i] || Output[i] > 1) signal++;
    }
    if(signal > 1) {
        QMessageBox::information(NULL, "Waring", "请检查最终状态!错误代码-I02", QMessageBox::Yes, QMessageBox::Yes);
        return -1;
    }
    //奇偶相同 有解
    if((sum1%2) == (sum2%2)) {
        return 1;
    }
    return 0;
}

//初始化OPEN表函数
LListPtr eightPuzzle::initOpenList()
{
    LListPtr plist = (LListPtr)malloc(sizeof(LList));
    nodePtr head = init();//头节点
    if (plist != NULL) {
        if (head != NULL) {
            plist->head = head;
            plist->tail = head;
        }
        else {
            free(plist);
            return NULL;
        }
    }
    else {
        printf("内部错误，分配内存到OPEN错误，请重试！错误代码-M02 \n");
        exit(0);
    }
    return plist;
}

//取OPEN表的第一个节点
nodePtr eightPuzzle::get_open_first(LListPtr open)
{
    nodePtr first = NULL;
    first = open->head;
    if (open->head == open->tail) {
        //只有一个节点
        open->head = NULL;
        open->tail = NULL;
    }
    else {
        open->head = open->head->next;
    }
    return first;
}

//初始化Close表
LListPtr eightPuzzle::initCloseList()
{
    LListPtr close = (LListPtr)malloc(sizeof(LList));
    if (close != NULL) {
        close->head = NULL;
        close->tail = NULL;
    }
    else {
        printf("内部错误，分配内存到Close错误，请重试！错误代码-M03 \n");
        exit(0);
    }
    return close;
}

/*比较两个结点
 * 0---相同
 * 1---不同
 */
int eightPuzzle::compare_node(nodePtr first, nodePtr second)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (first->matrix[i][j] != second->matrix[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

/*遍历CLOSE查找该状态是否已经寻找过
 * 0---未访问
 * 1---已访问
*/
int eightPuzzle::travel_close(LListPtr close, nodePtr expand_node)
{
    nodePtr tmp = NULL;
    if (close->head == NULL) {//CLOSE表空
        return 0;
    }
    tmp = close->head;
    while (tmp != NULL) {
        if (!compare_node(tmp, expand_node)) {
            if (tmp->gx > expand_node->gx) {
                tmp->gx = expand_node->gx;
                tmp->fx = tmp->hx + tmp->gx;
                tmp->hide_pre = expand_node->hide_pre;
            }
            break;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

//寻找0格
int eightPuzzle::findZero(nodePtr node)
{
    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (node->matrix[i][j] == 0) {
                ans = (i+1)*10 + j;
            }
        }
    }
    return ans;
}


//将节点加到OPEN表里
void eightPuzzle::add_to_open(LListPtr open, nodePtr node)
{
    nodePtr ptr = NULL, prePtr = NULL;
    //OPEN如果是空表就添加为新表头
    if (open->head == NULL) {
        open->head = node;
        open->tail = node;
    }
    else {
        //如果OPEN不是空表就按FX值由小到大插入
        ptr = open->head;
        while (ptr != NULL && ptr->fx <= node->fx) {
            prePtr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            open->tail->next = node;
            open->tail = node;
        }
        else {
            //插入到prePtr 和 ptr 中间
            if (prePtr == NULL) {
                node->next = open->head;
                open->head = node;
            }
            else {
                prePtr->next = node;
                node->next = ptr;
            }
        }
    }
    ptr = NULL;
    prePtr = NULL;
}

//将to_expand节点加入closed表，结束该节点的拓展流程
void eightPuzzle::add_to_close(LListPtr close, nodePtr node)
{
    if (close->head == NULL) {
        close->head = node;
        close->tail = node;
    }
    else {
        node->next = NULL;
        close->tail->next = node;
        close->tail = node;
    }
}


//根据dir = 1 2 3 4进行上 下 左 右填充
void eightPuzzle::step(int x, int y, int dir, nodePtr edge, LListPtr open, LListPtr closed)
{
    nodePtr new_node = NULL;
    new_node = (nodePtr)malloc(sizeof(node));   //
    if (new_node) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <N; j++) {
                new_node->matrix[i][j] = edge->matrix[i][j];
            }
        }
        switch (dir) {
            case 1:
                new_node->matrix[x][y] = new_node->matrix[x+1][y];
                new_node->matrix[x+1][y] = 0;
                break;
            case 2:
                new_node->matrix[x][y] = new_node->matrix[x-1][y];
                new_node->matrix[x-1][y] = 0;
                break;
            case 3:
                new_node->matrix[x][y] = new_node->matrix[x][y+1];
                new_node->matrix[x][y+1] = 0;
                break;
            case 4:
                new_node->matrix[x][y] = new_node->matrix[x][y-1];
                new_node->matrix[x][y-1] = 0;
                break;
            default:
                break;
        }
        new_node->gx = edge->gx + 1;
        new_node->hide_pre = edge;
        new_node->next = NULL;
        new_node->hx = cal_hx(new_node);
        new_node->fx = new_node->hx + new_node->gx;
        if (!travel_close(closed, new_node)) {
            //没走过 加入OPEN表
            add_to_open(open, new_node);
            new_node = NULL;
        }
        else {
            //走过 释放节点
            free(new_node);
            new_node = NULL;
        }
    }
    else {
        printf("分配内存失败 -M04新节点内存分配失败\n");
        exit(0);
    }
}

//根据0的位置进行移动并进行试探
//进行判重 如果已有则判断步数哪个更优 不存在则加入open表
void eightPuzzle::have_a_try(int x, int y, nodePtr edge, LListPtr open, LListPtr closed)
{
    int count = 0;
    if (x == 1 && y == 1) {             //[1][1]    上下左右
        count = 0;
        while (++count < 5) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 3:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                case 4:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }

                default:
                    break;
            }
        }
    }
    else if (x == 1 && y == 0) {        //[1][0]    上下左
        count = 0;
        while (++count < 4) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 3:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }
    }
    else if (x == 1 && y == 2) {        //[1][2]    上下右
        count = 0;
        while (++count < 4) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 3:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }    }
    else if (x == 0 && y == 1) {        //[0][1]    上左右
        count = 0;
        while (++count < 4) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                case 3:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }
    }
    else if (x == 2 && y == 1) {        //[2][1]    下左右
        count = 0;
        while (++count < 4) {
            switch (count) {
                case 1:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                case 3:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }    }
    else if (x == 0 && y == 0) {        //[0][0]    上左
        count = 0;
        while (++count < 3) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }    }
    else if (x == 0 && y == 2) {        //[0][2]    上右
        count = 0;
        while (++count < 3) {
            switch (count) {
                case 1:
                {
                    step(x, y, 1, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }    }
    else if (x == 2 && y == 0) {        //[2][0]    下左
        count = 0;
        while (++count < 3) {
            switch (count) {
                case 1:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 3, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }
    }
    else {                              //[2][2]    下右
        count = 0;
        while (++count < 3) {
            switch (count) {
                case 1:
                {
                    step(x, y, 2, edge, open, closed);
                    break;
                }
                case 2:
                {
                    step(x, y, 4, edge, open, closed);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

//拓展该节点的下一个状态
void eightPuzzle::expand_next(LListPtr open, LListPtr closed, nodePtr to_expand)
{
    int position = 0, position_x = 0, position_y = 0;
    position = findZero(to_expand);
    position_x = position / 10 - 1;
    position_y = position % 10;
    have_a_try(position_x, position_y, to_expand, open, closed);
}

//1为目标节点 0则不是
int eightPuzzle::check_now(nodePtr node)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (node->matrix[i][j] != des_matrix[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}



//find QLabel
QLabel* eightPuzzle::find_label(int i)
{
    int a = i / 10 - 1;
    int b = i % 10;
    switch(a*3 + b + 1) {
    case 1:
        return ui->show1;
        break;
    case 2:
        return ui->show2;
        break;
    case 3:
        return ui->show3;
        break;
    case 4:
        return ui->show4;
        break;
    case 5:
        return ui->show5;
        break;
    case 6:
        return ui->show6;
        break;
    case 7:
        return ui->show7;
        break;
    case 8:
        return ui->show8;
        break;
    case 9:
        return ui->show9;
        break;
    }
}

//recursion output
//循环输出
int eightPuzzle::recursion_output(nodePtr node)
{
    if (node != NULL) {
        int i = recursion_output(node->hide_pre);

        if (i == 0) {
            ui->show1->setText(QString::number(node->matrix[0][0]));
            ui->show2->setText(QString::number(node->matrix[0][1]));
            ui->show3->setText(QString::number(node->matrix[0][2]));
            ui->show4->setText(QString::number(node->matrix[1][0]));
            ui->show5->setText(QString::number(node->matrix[1][1]));
            ui->show6->setText(QString::number(node->matrix[1][2]));
            ui->show7->setText(QString::number(node->matrix[2][0]));
            ui->show8->setText(QString::number(node->matrix[2][1]));
            ui->show9->setText(QString::number(node->matrix[2][2]));
            int result = findZero(node);
            find_label(result)->setText("");
            return result;
        }
        else {
            int temp = findZero(node);
            int row_now = i/10 - 1;
            int column_now = i%10;
            int a = node->matrix[row_now][column_now];
            QLabel* label_i = find_label(i);
            QLabel* label_temp = find_label(temp);

            QElapsedTimer t;
            t.start();
            while(t.elapsed() < 1000)
                QCoreApplication::processEvents();

            label_i->setText(QString::number(a));
            label_temp->setText("");

            return temp;
        }
    }
    else {
        return 0;
    }
}


nodePtr eightPuzzle::solve()
{
    int end = 1;
    nodePtr first = NULL;
    while (end && open->head!=NULL) {
        first = get_open_first(open);
        if (check_now(first)) {
            end = 0;
            break;
        }
        add_to_close(close, first);
        expand_next(open, close, first);
        first = NULL;
    }
    if (end) {
        QMessageBox::critical(this, "无解", "无解哦QAQ", QMessageBox::Yes, QMessageBox::Yes);
        return NULL;
    }
    return first;
}


void eightPuzzle::free_list(LListPtr list)
{
    nodePtr node = NULL;
    if (list != NULL) {
        while (list->head != NULL) {
            node = list->head;
            list->head = list->head->next;
            free(node);
            node = NULL;
        }
        free(list);
        list = NULL;
    }
}
