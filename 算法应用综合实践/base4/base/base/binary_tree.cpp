#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // ���������������
    void helper(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }

    // �ҵ���ӽ�Ŀ��ֵ�� k ����
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (k == 1)
            return { root->val };
        vector<int> inorder;
        helper(root, inorder);
        vector<int> res;
        int start = 0;
        int end = inorder.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (inorder[mid] == target) {
                res.push_back(inorder[mid]);
                k--;
                break;
            } else if (inorder[mid] < target)
                start = mid;
            else
                end = mid;
        }
        end = start + 1;
        while (k--) {
            if (start >= 0 && end < inorder.size()) {
                if (abs(inorder[start] - target) < abs(inorder[end] - target)) {
                    res.push_back(inorder[start]);
                    start--;
                } else {
                    res.push_back(inorder[end]);
                    end++;
                }
            } else if (start >= 0) {
                res.push_back(inorder[start]);
                start--;
            } else {
                res.push_back(inorder[end]);
                end++;
            }
        }
        return res;
    }
};

// �����������ĸ�������
TreeNode* createTree(const vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = createTree(nodes, 2 * index + 1);
    root->right = createTree(nodes, 2 * index + 2);
    return root;
}

// ��ӡ����ĸ�������
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // ����1
	Solution solution;
    /*
    vector<int> nodes1 = {1};
    double target1 = 0.0;
    int k1 = 1;
    TreeNode* root1 = createTree(nodes1, 0);
    Solution solution;
    vector<int> result1 = solution.closestKValues(root1, target1, k1);
    cout << "����1�Ľ��: ";
    printResult(result1);
    */
    // ����2
    vector<int> nodes2 = {1, 2, 4, -1, 3, 6, 2};
    double target2 = 1.275;
    int k2 = 2;
    TreeNode* root2 = createTree(nodes2, 0);
    vector<int> result2 = solution.closestKValues(root2, target2, k2);
    cout << "����2�Ľ��: ";
    printResult(result2);

    return 0;
}