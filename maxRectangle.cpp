#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:
输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

 */ 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int heights[n];
        memset(heights, 0, sizeof(heights));
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')  heights[j] += 1;
                else heights[j] = 0;
            }
            max_area = max(max_area, largestRectangleArea(heights, n));
            //cout << max_area << endl;
        }
        return max_area;
    }
    int largestRectangleArea(int *heights, int n) {
        int max_area = 0;
        stack<int> stk;
        if (n == 0) return 0;
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            while (stk.top() != -1 && heights[stk.top()] > heights[i]) {
                int temp = stk.top();
                stk.pop();
                max_area = max(max_area, heights[temp] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int temp = stk.top();
            stk.pop();
            max_area = max(max_area, heights[temp] * (n - 1 - stk.top()));
        }
        return max_area;
    }
};