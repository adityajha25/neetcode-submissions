class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);

        //[1,2,4,6]
        //[0,1,2,8]
        //[48, 24, 6, 1]

        int prod=nums[0];
        for (int i=1;i<nums.size();i++) {
            left[i] = prod;
            prod*=nums[i];
        }

        prod=nums.back();
        for (int i=nums.size()-2;i>-1;i--) {
            right[i] = prod;
            prod*=nums[i];
        }

        for (int i=0;i<left.size();i++) {
            left[i] = left[i]*right[i];
        }
        
        return left;
    }
};
