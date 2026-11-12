class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numbers = set(nums)

        counter=0

        for item in nums:
            local=0
            if item-1 not in numbers:
                while item in numbers:
                    local+=1
                    item+=1
            counter = max(local, counter)
        
        return counter