/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    
     // @param matrix 一个布尔二维矩阵
     // @return 一个整数
     
    int maximalRectangle(vector<vector<bool> >& matrix) {
        // 如果矩阵为空，返回0
        if (matrix.empty()) {
            return 0;
        }
        int ans = 0; // 用于存储最大矩形面积
        int n = matrix.size(); // 矩阵的行数
        int m = matrix[0].size(); // 矩阵的列数

        // 创建一个与矩阵列数相同的临时数组，初始化为0
        vector<int> temp(m, 0);
        // 创建一个dp数组，用于存储每个位置上方有多少连续的1
        vector<vector<int>> dp(n, temp);

        // 遍历矩阵，计算每个位置上方有多少连续的1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && matrix[i][j]) { // 如果是第一行且当前位置为1
                    dp[i][j] = 1; // 直接赋值为1
                    continue; // 跳过后续操作
                }
                if (matrix[i][j]) { // 如果当前位置为1
                    dp[i][j] = dp[i - 1][j] + 1; // 计算当前位置上方有多少连续的1
                }
            }
        }

        // 遍历每一行，把每一行作为底找最大矩形
        for (int i = 0; i < n; i++) {
            ans = max(ans, largestRectangleArea(dp[i])); // 更新最大矩形面积
        }
        return ans; // 返回最大矩形面积
    }

    // 计算直方图中最大矩形面积的辅助函数
    int largestRectangleArea(vector<int>& height) {
        stack<int> S; // 创建一个栈用于存储柱子的索引
        height.push_back(0); // 在高度数组末尾添加一个0，确保所有柱子都能被处理
        int sum = 0; // 用于存储最大矩形面积
        for (int i = 0; i < height.size(); i++) {
            if (S.empty() || height[i] > height[S.top()]) { // 如果栈为空或当前高度大于栈顶高度
                S.push(i); // 将当前索引入栈
            } else {
                int tmp = S.top(); // 获取栈顶索引
                S.pop(); // 弹出栈顶索引
                sum = max(sum, height[tmp] * (S.empty() ? i : i - S.top() - 1)); // 计算矩形面积并更新最大面积
                i--; // 拿着右边界，寻找左边界
            }
        }
        return sum; // 返回最大矩形面积
    }
};

int main() {
    // 创建样例1的矩阵
    vector<vector<bool>> matrix1 = {
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };

    // 创建样例2的矩阵
    vector<vector<bool>> matrix2 = {
        {0, 0},
        {0, 1}
    };

    // 创建 Solution 对象
    Solution solution;

    // 计算样例1的最大矩形面积
    int result1 = solution.maximalRectangle(matrix1);
    // 输出样例1的结果
    cout << "样例1的最大矩形面积: " << result1 << endl;

    // 计算样例2的最大矩形面积
    int result2 = solution.maximalRectangle(matrix2);
    // 输出样例2的结果
    cout << "样例2的最大矩形面积: " << result2 << endl;

    return 0;
}

*/