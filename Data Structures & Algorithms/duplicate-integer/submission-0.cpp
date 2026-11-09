#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen = {};
        for (int i=0; i<size(nums); i++) {
            if (seen.contains(nums[i])) {
                return true;
            } else {
                seen.insert(nums[i]);
            }
        }
        return false;
    }
};