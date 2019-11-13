#include<iostream>
#include<stack>
using namespace std;

/**
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

 */ 
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) {
            return 0;
        }
        int dp[1000] = {0};
        int max_dp = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >=0 ? dp[i - dp[i - 1] - 2]: 0);
                }
                max_dp = max(max_dp, dp[i]);
            }
        }
        return max_dp;
    }
};

int main() {
    Solution *so = new Solution();
    cout << so -> longestValidParentheses("()()") << endl;
}