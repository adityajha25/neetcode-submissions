class Solution:
    def climbStairs(self, n: int) -> int:
        first=1
        second=2
        if n==2:
            return 2
        elif n==1:
            return 1
        curr=first+second

        for i in range(n-3):
            first=second
            second=curr
            curr=first+second
        

        return curr