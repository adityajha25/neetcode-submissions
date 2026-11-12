class Solution:

    def encode(self, strs: List[str]) -> str:
        ans = ""

        for string in strs:
            ans+="|"
            ans+=str(len(string))
            ans+="|"
            ans+=string
        
        return ans

    def decode(self, s: str) -> List[str]:
        
        items = []

        i=0
        while i < len(s):
            i+=1
            length = ""
            while s[i] != "|":
                length+=s[i]
                i+=1
            
            length = int(length)
            i+=1
            curr=""
            for j in range(i, i+length):
                curr+=s[j]
            items.append(curr)
            i+=length
        
        return items

            
