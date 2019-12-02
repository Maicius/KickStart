#include<iostream>
#include<vector>
using namespace std;
/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */ 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int left[n], right[n];
        left[0] = height[0];
        for(int i = 1; i < n;i++){
            left[i] = max(height[i], left[i - 1]);
        }
        right[n-1] = height[n - 1];
        for(int j = n - 2; j >=0; j--) {
            right[j] = max(height[j], right[j + 1]);
        }
        int res = 0;
        int temp;
        for(int i = 1; i < n - 1;i++) {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};