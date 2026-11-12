class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxmax, max_num = nums[0], nums[0]
        for i in range(1, len(nums)):
            max_num = max(max_num+nums[i], nums[i])
            maxmax = max(maxmax, max_num)
        return maxmax