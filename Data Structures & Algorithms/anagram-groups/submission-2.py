class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams = {}
        
        for item in strs:
            freqs = [0] * 26

            for char in item:
                x=freqs[ord(char)-ord('a')]
                freqs[ord(char)-ord('a')] = x+1
            
            a = anagrams.get(tuple(freqs), [])
            a.append(item)
            anagrams[tuple(freqs)] = a

        ans=[]
        for key in anagrams:
            local=[]
            for val in anagrams[key]:
                local.append(val)
            ans.append(local)

        return ans