#include<iostream>

/**
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *

 */ 
using namespace std;
class Solution {
public:
    int dp[1000][1000];
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        const int N = 1000;
        
        dp[0][0] = 1;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '*' && dp[0][i - 1]) {
                dp[0][i + 1] = 1;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (p[j] == '*') {
                    if (p[j - 1] != s[i] && p[j - 1] != '.') dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                }
                            /*
                            dp[i][j] = dp[i-1][j] // 多个字符匹配的情况	
                            or dp[i][j] = dp[i][j-1] // 单个字符匹配的情况
                            or dp[i][j] = dp[i][j-2] // 没有匹配的情况
                             */
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    Solution *so = new Solution();
    string a = "aasdfasdfasdfasdfas";
    string b = "aasdf.*asdf.*asdf.*asdf.*s";
    cout << so -> isMatch("", ".*") << endl;
}