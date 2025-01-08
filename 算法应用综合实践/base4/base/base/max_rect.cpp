/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    
     // @param matrix һ��������ά����
     // @return һ������
     
    int maximalRectangle(vector<vector<bool> >& matrix) {
        // �������Ϊ�գ�����0
        if (matrix.empty()) {
            return 0;
        }
        int ans = 0; // ���ڴ洢���������
        int n = matrix.size(); // ���������
        int m = matrix[0].size(); // ���������

        // ����һ�������������ͬ����ʱ���飬��ʼ��Ϊ0
        vector<int> temp(m, 0);
        // ����һ��dp���飬���ڴ洢ÿ��λ���Ϸ��ж���������1
        vector<vector<int>> dp(n, temp);

        // �������󣬼���ÿ��λ���Ϸ��ж���������1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && matrix[i][j]) { // ����ǵ�һ���ҵ�ǰλ��Ϊ1
                    dp[i][j] = 1; // ֱ�Ӹ�ֵΪ1
                    continue; // ������������
                }
                if (matrix[i][j]) { // �����ǰλ��Ϊ1
                    dp[i][j] = dp[i - 1][j] + 1; // ���㵱ǰλ���Ϸ��ж���������1
                }
            }
        }

        // ����ÿһ�У���ÿһ����Ϊ����������
        for (int i = 0; i < n; i++) {
            ans = max(ans, largestRectangleArea(dp[i])); // �������������
        }
        return ans; // �������������
    }

    // ����ֱ��ͼ������������ĸ�������
    int largestRectangleArea(vector<int>& height) {
        stack<int> S; // ����һ��ջ���ڴ洢���ӵ�����
        height.push_back(0); // �ڸ߶�����ĩβ���һ��0��ȷ���������Ӷ��ܱ�����
        int sum = 0; // ���ڴ洢���������
        for (int i = 0; i < height.size(); i++) {
            if (S.empty() || height[i] > height[S.top()]) { // ���ջΪ�ջ�ǰ�߶ȴ���ջ���߶�
                S.push(i); // ����ǰ������ջ
            } else {
                int tmp = S.top(); // ��ȡջ������
                S.pop(); // ����ջ������
                sum = max(sum, height[tmp] * (S.empty() ? i : i - S.top() - 1)); // ����������������������
                i--; // �����ұ߽磬Ѱ����߽�
            }
        }
        return sum; // �������������
    }
};

int main() {
    // ��������1�ľ���
    vector<vector<bool>> matrix1 = {
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };

    // ��������2�ľ���
    vector<vector<bool>> matrix2 = {
        {0, 0},
        {0, 1}
    };

    // ���� Solution ����
    Solution solution;

    // ��������1�����������
    int result1 = solution.maximalRectangle(matrix1);
    // �������1�Ľ��
    cout << "����1�����������: " << result1 << endl;

    // ��������2�����������
    int result2 = solution.maximalRectangle(matrix2);
    // �������2�Ľ��
    cout << "����2�����������: " << result2 << endl;

    return 0;
}

*/