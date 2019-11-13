#include<iostream>
using namespace std;
/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 */ 
class Solution {
public:

    // 中心拓展法
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string res = s.substr(0, 1);
        int max_len = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            string odd = centerSpread(s, i, i);
            string even = centerSpread(s, i, i + 1);
            string str = odd.size() > even.size() ? odd : even;
            if (str.size() > max_len) {
                max_len = str.size();
                res = str;
            }
        }
        return res;
    }

    string centerSpread(string s,int left,int right) {
        while (left >= 0 && right <= s.size()) {
            if (s[left] == s[right]) {
                left--;
                right++;
            } else {
                break;
            }
        }
        return s.substr(left + 1, right - left - 1);
    }

    // 马拉车算法
    int centerSpread(string str, int center) {
        int left = center - 1;
        int right = center + 1;
        int step = 0;
        while (left >= 0 && right <= str.size() && str[left] == str[right]){
            left--;
            right++;
            step++;
        }
        return step;
    }
    string longestPalindrome2(string s) {
        int size = s.size();
        if (size < 2) return s;
        string str = "#";
        for (int i = 0; i < size; i++) {
            str += s[i];
            str += "#";
        } 
        int sSize = str.size();
        int maxLen = 1;
        int start = 0;
        for (int i = 0; i < sSize; i++) {
            int curLen = centerSpread(str, i);
            if (curLen > maxLen) {
                maxLen = curLen;
                start = (i - maxLen) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    //动态规划
    string longestPalindrome3(string s) {
        int dp[1000][1000] = {0};
        int size = s.size();
        if (size <= 1) return s;
        int longest = 1;
        string longest_str = s.substr(0, 1);
        for (int r = 1; r < size; r++) {
            for (int l = 0; l < r; l++) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = 1;
                    if (r - l + 1 > longest) {
                        longest = r - l + 1;
                        longest_str = s.substr(l, r - l + 1);
                    }
                }
            }
        }
        return longest_str;
    }

    
};