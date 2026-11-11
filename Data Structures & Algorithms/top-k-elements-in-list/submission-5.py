class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}

        for item in nums:
            x = freq.get(item,0)
            freq[item] = (x+1)
        
        freq_sorted = dict(sorted(freq.items(), key=lambda x: x[1], reverse=True))

        ans = []
        for key in freq_sorted:
            ans.append(key)
            if len(ans) == k:
                break
        return ans
        