class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
         
         if len(s) != len(t):
            return False

         counter = [0] * 26
         nonzero = 0

         for i in range(len(s)):
            if counter[ord(s[i]) - ord('a')] == -1:
                nonzero-=1
            elif counter[ord(s[i]) - ord('a')] == 0:
                nonzero+=1

            counter[ord(s[i]) - ord('a')] +=1

            if counter[ord(t[i]) - ord('a')] == 1:
                nonzero-=1
            elif counter[ord(t[i]) - ord('a')] == 0:
                nonzero+=1

            counter[ord(t[i]) - ord('a')] -=1
        
         return nonzero==0