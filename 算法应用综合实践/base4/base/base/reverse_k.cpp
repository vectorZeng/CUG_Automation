/*
#include <iostream>

// ���嵥����ڵ�ṹ
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ��� k <= 0 ��������Ϊ�ջ�������ֻ��һ���ڵ㣬ֱ�ӷ���ԭ����
        if (k <= 0 || head == NULL || head->next == NULL) {
            return head;
        }

        // ����һ���ƽڵ㣬ָ������ͷ
        ListNode dummy(1);
        dummy.next = head;
        ListNode* prev = &dummy; // prev ָ���ƽڵ�
        ListNode* end = head; // end ָ������ͷ

        // ��������
        while (end != NULL) {
            // �ƶ� end ָ�룬ʹ��ָ��� k ���ڵ�
            for (int i = 1; i < k && end != NULL; i++) {
                end = end->next;
            }
            // ���ʣ��ڵ㲻�� k ����ֱ������ѭ��
            if (end == NULL) break;

            // ��¼Ҫ��ת�����������ʼ�ڵ�ͽ����ڵ����һ���ڵ�
            ListNode* start = prev->next;
            ListNode* next = end->next;
            end->next = NULL; // �Ͽ�������

            // ��ת������������ת������������ӵ�ǰһ����
            prev->next = reverseList(start);
            start->next = next;

            // ���� prev �� end ָ�룬׼����ת��һ��������
            prev = start;
            end = prev->next;
        }
        // �����µ�����ͷ
        return dummy.next;
    }

private:
    // ��ת����ĸ�������
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; // prev ָ��ǰһ���ڵ�
        ListNode* curr = head; // curr ָ��ǰ�ڵ�
        while (curr != NULL) {
            ListNode* next = curr->next; // ��¼��һ���ڵ�
            curr->next = prev; // ��ת��ǰ�ڵ��ָ��
            prev = curr; // ���� prev ָ��
            curr = next; // ���� curr ָ��
        }
        return prev; // ���ط�ת�������ͷ
    }
};

// ��ӡ����ĺ���
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
    // �������� 1->2->3->4->5->NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(NULL);
    // ���� k
    int k = 2;

    // ���� Solution ����
    Solution solution;

    // ���� reverseKGroup ����
    ListNode* newHead = solution.reverseKGroup(head, k);

    // ��ӡ�޸ĺ������
    printList(newHead);

    return 0;
}
*/