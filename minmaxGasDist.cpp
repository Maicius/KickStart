#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * 假设我们在一条水平数轴上，列表 stations 来表示各个加油站的位置，加油站分别在 stations[0], stations[1], ..., stations[N-1] 的位置上，其中 N = stations.length。

现在我们希望增加 K 个新的加油站，使得相邻两个加油站的距离 D 尽可能的最小，请你返回 D 可能的最小值。
 */ 
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int mxDiff = -1;
        for (int i = 1; i < stations.size(); ++i)
        mxDiff = max(mxDiff, stations[i] - stations[i - 1]);
        double start = floor(mxDiff / (K + 1));
        double end = ceil(mxDiff);
        /**
         * 二分查找，查找的目标是在满足count <= K的情况下，最小化距离
         */ 
        while (abs(start - end) > 1e-6) {
            double mid = start + (end - start) / 2;
            int count = 0;
            for (int i = 1; i < stations.size(); ++i)
                count += ceil(((double)stations[i] - stations[i - 1]) / mid) - 1;
            if (count > K)
                start = mid + 1e-6;
            else
                end = mid;
        }

        return start;
    }
};