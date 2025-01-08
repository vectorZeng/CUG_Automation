/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 初始化有向图和入度数组
        edges.resize(numCourses);
        indeg.resize(numCourses);
        
        // 构建有向图和入度数组
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // 从队首取出一个节点
            int u = q.front();
            q.pop();
            // 放入答案中
            result.push_back(u);
            // 遍历该节点的所有邻接节点
            for (int v : edges[u]) {
                --indeg[v]; // 将邻接节点的入度减1
                // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 如果答案中包含的课程数量不等于总课程数，说明存在环，无法完成所有课程
        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};

int main() {
    // 样例
    int n1 = 5;
    vector<vector<int>> prerequisites1 = { {1, 0},{1,2},{3,2} };

    // 创建 Solution 对象
    Solution solution;

    // 计算样例1的课程顺序
    vector<int> result1 = solution.findOrder(n1, prerequisites1);
    // 输出样例1的结果
    cout << "样例的课程顺序: ";
    for (int course : result1) {
        cout << course << " ";
    }
    cout << endl;


    return 0;
}*/