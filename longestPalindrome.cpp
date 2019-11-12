#include<iostream>
using namespace std;

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
    
};