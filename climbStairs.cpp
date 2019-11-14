#include<iostream>
/**
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
 */ 
typedef long long ll;
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        ll res = 0;
        if (n <= 2) return n;
        ll temp1 = 1, temp2 = 2;
        for (int i = 3; i <= n; i++) {
            res = temp1 + temp2;
            temp1 = temp2;
            temp2 = res;
        }
        return res;
    }

    int climbStairs2(int n) {
        ll res = 0;
        if (n <= 2) return n;
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

int main() {
    Solution *so = new Solution();
    cout << so->climbStairs(100000) << endl; 
}