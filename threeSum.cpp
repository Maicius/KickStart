#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
/**
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */ 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int> > map;
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) return res;
            int l = i + 1;
            int r = size - 1;
            while (l < r) {
                //cout << l << endl;
                int sum_v = nums[i] + nums[r] + nums[l];
                if (sum_v == 0) {
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    res.push_back(temp);
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                } else if (sum_v < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};