class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, item in enumerate(nums):
            complement = target-item
            if item in seen:
                return [seen[item], i]
            seen[complement] = i
        
        return []