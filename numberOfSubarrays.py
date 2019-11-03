class Solution:
    def numberOfSubarrays(self, nums, k):
        count = 0
        odd = []
        if k == 0:
            return 0
        for i in range(len(nums)):
            if (nums[i] % 2 != 0):
                odd.append((i, nums[i]))
        if len(odd) < k:
            return 0
        for i in range(0, len(odd) - k + 1, 1):
            begin = 0 if i == 0 else odd[i - 1][0] + 1
            if (i + k - 1) == len(odd) - 1:
                end = len(nums) - 1
            else:
                end = odd[i + k][0] - 1
            count += (odd[i][0] - begin + 1) * (end - odd[i + k - 1][0] + 1)
        return count

    def solution2(self, nums, k):
        s = 0
        sum = {}
        sum[s] = 1
        res = 0
        for i in range(0, len(nums)):
            if nums[i] % 2 == 1:
                s += 1
            if s - k >= 0:
                res += sum[s - k]
            if s in sum:
                sum[s] += 1
            else:
                sum[s] = 1
        return  res

so = Solution()
num = [2,2,2,1,2,2,1,2,2,2]
num1 = [1,1,2,1,1]
k = 3
print(so.solution2(num1, k))
print(so.numberOfSubarrays(num1, k))
