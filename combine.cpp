#include<iostream>
#include<vector>
using namespace std;
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int *a = new int[n];
        bool *visited = new bool[n];
        for(int i = 0; i < n;i++) {
            a[i] = i + 1;
            visited[i] = false;
        }
        vector<vector<int> > res; 
        dfs(0, 0, n, k, a, visited, res);
        return res;
    }
    void dfs(int pos, int cnt, int n, int k, int a[], bool visited[], vector<vector<int> > &res) {
        if (cnt == k) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    temp.push_back(a[i]);
                }
            }
            res.push_back(temp);
            return;
        }
        if (pos == n) return;
        if(!visited[pos]) {
            visited[pos] = true;
            dfs(pos + 1, cnt + 1, n, k, a, visited, res);
            visited[pos] = false;
        }
        dfs(pos + 1, cnt, n, k, a,visited, res);
    }
};