#include<iostream>
#include<vector>
using namespace std;
/**
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

https://leetcode-cn.com/problems/wildcard-matching/
 */ 
class Solution {
public:
    
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        if (p_len == 0) return s_len == 0;
        bool dp[s_len + 1][p_len + 1];
        for (int i = 0; i <= s_len; i++) {
            for(int j = 0; j <= p_len;j ++) {
                dp[i][j] = false;
            }
        }
        // vector<vector<bool> > dp(s_len + 1, vector<bool>(p_len + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p_len; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];
            else
                break;
        }
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s_len][p_len];
    }
};

int main() {
    Solution *so = new Solution();
    cout << so ->isMatch("aab", "c*a*b") << endl;
    cout << so ->isMatch("adceb", "*a*b") << endl;
}