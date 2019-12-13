#include<vector>
#include<iostream>
using namespace std;
/**
 * 对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：

对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。

那么数组 A 是漂亮数组。

给定 N，返回任意漂亮数组 A（保证存在一个）。
 */ 
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        if (N == 2) return {1, 2};
        if (N == 3) return {1, 3, 2};
        if (N == 4) return {2, 1, 4, 3};

        vector<int> temp = {2, 1, 4, 3};
        while (temp.size() < N) {
            for (auto &i : temp) {
                i = i * 2 - 1;
            }
            int s = temp.size();
            for (int i = 0; i < s; i++) {
                temp.push_back(temp[i] + 1);
            }
        }
        for(vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++){
            if(*iter > N){		
                iter = temp.erase(iter);
                iter--;			
            }
	    }
        //temp.erase(remove_if(temp.begin(), temp.end(), [=](int i) {return i > N;}), temp.end());
        return temp;
    }
};