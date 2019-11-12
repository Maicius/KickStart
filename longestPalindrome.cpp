#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string res = s.at[0];
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
};