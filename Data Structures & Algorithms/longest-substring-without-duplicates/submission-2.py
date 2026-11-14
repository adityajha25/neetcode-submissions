class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start=0
        count=0
        seen = set()

        # zxyzxyz

        for i in range(len(s)):
            while s[i] in seen:
                seen.remove(s[start])
                start+=1
            seen.add(s[i])
            count=max(count, i-start+1)
        return count