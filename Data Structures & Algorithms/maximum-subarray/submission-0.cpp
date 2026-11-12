class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxmax=nums[0];
        int max = nums[0];
        for (int i=1;i<nums.size();i++) {
            if (max+nums[i] > nums[i]) {
                max = max+nums[i];
            } else {
                max = nums[i];
            }
            maxmax = std::max(max, maxmax);
        }
        return maxmax;
    }
};
