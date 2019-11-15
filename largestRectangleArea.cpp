#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */ 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long max_area = 0;
        int n = heights.size();
        stack<int> stk;
        if (n == 0) return 0;
        stk.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 && heights[stk.top()] > heights[i]) {
                long long temp = stk.top();
                stk.pop();
                max_area = max(max_area, (long long)heights[temp] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            long long temp = stk.top();
            stk.pop();
            max_area = max(max_area, (long long)heights[temp] * (n - 1 - stk.top()));
        }
        return (int)max_area;
    }
};


int main() {
    Solution *so = new Solution();
    int data[6] = {2, 1, 5, 6, 2, 3};
    vector<int> d1(data, data + 6);
    cout << so -> largestRectangleArea(d1) << endl;
}

