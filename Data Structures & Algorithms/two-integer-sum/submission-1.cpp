#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i=0;i<size(nums); i++) {
            if (seen.contains(nums[i])) {
                return {seen[nums[i]], i};
            } else {
                seen[target-nums[i]] = i;
            }
        }
    }
};
