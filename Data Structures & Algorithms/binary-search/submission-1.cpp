class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while (left <= right) {
            int middle = (left+right) / 2;
            int item = nums[middle];

            if (item > target) {
                right=middle-1;
            } else if (item < target) {
                left = middle+1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};
