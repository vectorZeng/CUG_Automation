/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // �洢����ͼ
    vector<vector<int>> edges;
    // �洢ÿ���ڵ�����
    vector<int> indeg;
    // �洢��
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // ��ʼ������ͼ���������
        edges.resize(numCourses);
        indeg.resize(numCourses);
        
        // ��������ͼ���������
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // ���������Ϊ 0 �Ľڵ���������
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // �Ӷ���ȡ��һ���ڵ�
            int u = q.front();
            q.pop();
            // �������
            result.push_back(u);
            // �����ýڵ�������ڽӽڵ�
            for (int v : edges[u]) {
                --indeg[v]; // ���ڽӽڵ����ȼ�1
                // ������ڽڵ� v �����Ϊ 0���Ϳ���ѡ v ��Ӧ�Ŀγ���
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        // ������а����Ŀγ������������ܿγ�����˵�����ڻ����޷�������пγ�
        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};

int main() {
    // ����
    int n1 = 5;
    vector<vector<int>> prerequisites1 = { {1, 0},{1,2},{3,2} };

    // ���� Solution ����
    Solution solution;

    // ��������1�Ŀγ�˳��
    vector<int> result1 = solution.findOrder(n1, prerequisites1);
    // �������1�Ľ��
    cout << "�����Ŀγ�˳��: ";
    for (int course : result1) {
        cout << course << " ";
    }
    cout << endl;


    return 0;
}*/