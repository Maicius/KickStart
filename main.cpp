#include<iostream>
using namespace std;
#include<vector>

/**
 * 题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

 思路：
 归并排序，求交换次数
 */



class Solution {
    int data[50][50];

public:
    int oddCells(int n, int m, vector<vector<int> >& indices) {


        for (int k = 0; k < indices.size(); k++) {
            vector<int> first = indices[k];
            for (int i = 0; i < m; i++) {
                data[first[0]][i] += 1;
                //cout << data[first[0]][i] << " ";
            }
            //cout << endl;
            for (int i = 0; i < n; i++) {
                data[i][first[1]] += 1;
            }
        }
        int res = 0;
        for (int i =0; i< n; i++) {
            for (int j = 0; j < m; j++) {
                cout << data[i][j] << " ";
                if (data[i][j] % 2 != 0) {
                    //cout << data[i][j] << " ";
                    res += 1;
                }
            }
            cout << endl;
        }
        return res;

    }
};

int main() {
    Solution *so = new Solution();
    vector<vector<int> > indices;
    int arr[5] = {1, 1};
    vector<int> temp(arr, arr + 2);
    indices.push_back(temp);
    int arr1[5] = {0, 0};
    vector<int> temp1(arr1, arr1 + 2);
    indices.push_back(temp1);
    int res = so -> oddCells(2, 2, indices);
    cout << res << endl;
}