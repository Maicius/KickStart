class Solution(object):
    def findNumberOfLIS(self, nums):
        N = len(nums)
        if N <= 1: return N
        lengths = [0] * N
        counts = [1] * N
        for j, num in enumerate(nums):
            for i in range(j):
                if nums[i] < nums[j]:
                    if lengths[i] >= lengths[j]:
                        lengths[j] = 1 + lengths[i]
                        counts[j] = counts[i]
                    elif lengths[i] + 1 == lengths[j]:
                        counts[j] += counts[i]
        print(lengths)
        longest = max(lengths)
        print(longest)
        return sum(c for i, c in enumerate(counts) if lengths[i] == longest)

if __name__ =='__main__':
    so = Solution()
    print(so.findNumberOfLIS([1, 4, 5, 2, 3, 6, 7]))