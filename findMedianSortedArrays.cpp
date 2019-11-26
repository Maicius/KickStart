#include<vector>
#include<iostream>
using namespace std;
/**
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

 */ 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int mid = (m + n + 1) / 2;
        int low = 0, upper = m, i, j;
        while (low <= upper) {
            i = (low + upper) / 2;
            j = mid - i;
            if (i > 0 && nums1[i - 1] > nums2[j]) upper = i - 1;
            else if (i < upper && nums2[j - 1] > nums1[i]) low =i + 1;
            else {
                int max_l = 0;
                if (i == 0) max_l = nums2[j - 1];
                else if (j == 0) max_l = nums1[i - 1];
                else {
                    max_l = max(nums1[i -1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) return max_l;

                int max_r = 0;
                if (i == m) max_r = nums2[j];
                else if (j == n) max_r = nums1[i];
                else max_r = min(nums2[j], nums1[i]);
                return (max_r + max_l) / 2.0;
            }
        }
        return 0.0;
    }
};