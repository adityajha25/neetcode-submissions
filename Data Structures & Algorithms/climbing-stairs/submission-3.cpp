class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        int curr = first+second;
        if (n==3) {
            return curr;
        } else if (n==2) {
            return second;
        } else if (n==1) {
            return first;
        }
        for (int i=0;i<n-3;i++) {
            first=second;
            second=curr;
            curr=first+second;
        }

        return curr;
    }
};
