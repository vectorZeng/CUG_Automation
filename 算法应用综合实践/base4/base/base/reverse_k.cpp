/*
#include <iostream>

// 定义单链表节点结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 如果 k <= 0 或者链表为空或者链表只有一个节点，直接返回原链表
        if (k <= 0 || head == NULL || head->next == NULL) {
            return head;
        }

        // 创建一个哑节点，指向链表头
        ListNode dummy(1);
        dummy.next = head;
        ListNode* prev = &dummy; // prev 指向哑节点
        ListNode* end = head; // end 指向链表头

        // 遍历链表
        while (end != NULL) {
            // 移动 end 指针，使其指向第 k 个节点
            for (int i = 1; i < k && end != NULL; i++) {
                end = end->next;
            }
            // 如果剩余节点不足 k 个，直接跳出循环
            if (end == NULL) break;

            // 记录要反转的子链表的起始节点和结束节点的下一个节点
            ListNode* start = prev->next;
            ListNode* next = end->next;
            end->next = NULL; // 断开子链表

            // 反转子链表，并将反转后的子链表连接到前一部分
            prev->next = reverseList(start);
            start->next = next;

            // 更新 prev 和 end 指针，准备反转下一个子链表
            prev = start;
            end = prev->next;
        }
        // 返回新的链表头
        return dummy.next;
    }

private:
    // 反转链表的辅助函数
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; // prev 指向前一个节点
        ListNode* curr = head; // curr 指向当前节点
        while (curr != NULL) {
            ListNode* next = curr->next; // 记录下一个节点
            curr->next = prev; // 反转当前节点的指针
            prev = curr; // 更新 prev 指针
            curr = next; // 更新 curr 指针
        }
        return prev; // 返回反转后的链表头
    }
};

// 打印链表的函数
void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val;
        if (head->next != NULL) {
            std::cout << "->";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // 创建链表 1->2->3->4->5->NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(NULL);
    // 定义 k
    int k = 2;

    // 创建 Solution 对象
    Solution solution;

    // 调用 reverseKGroup 函数
    ListNode* newHead = solution.reverseKGroup(head, k);

    // 打印修改后的链表
    printList(newHead);

    return 0;
}
*/