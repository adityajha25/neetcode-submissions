class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> theSet(nums.begin(), nums.end());

        int count=0;
        for (int i=0;i<nums.size();i++) {
            int x=nums[i];
            int local=0;
            if (theSet.count(x-1)!=1) {
                
                while (theSet.count(x)==1) {
                    local+=1;
                    x+=1;
                }
            }
            count = std::max(count, local);
        }
        return count;
    }
};
