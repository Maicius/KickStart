#include<iostream>
#include<vector>
using namespace std;

/**
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

https://leetcode-cn.com/problems/maximum-subarray/
 */ 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int dp[size];
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i <= size; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
    int maxSubArray2(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    int data[9] = {1};
    vector<int> temp(data, data + 1);
    cout << so->maxSubArray(temp) << endl;
}