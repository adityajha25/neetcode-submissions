class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency = {};
        frequency.reserve(nums.size());
        int max=0;
        for (int i=0;i<nums.size(); i++) {
            int& ref = frequency[nums[i]];
            ref+=1;
            max = std::max(max, ref);
        }

        std::vector<vector<int>> buckets(max);
        for (auto& [key, value] : frequency) {
            buckets[value-1].push_back(key);
        }

        vector<int> answer;

        for (int i=max-1; i>=0;i--) {
            bool breaker=false;
            for (int j=0;j<buckets[i].size();j++) {
                answer.push_back(buckets[i][j]);
                
                if (answer.size() == k){
                    breaker = true;
                    break;
                }
            }
            if (breaker){
                break;
            }
        }

        return answer;


    }
};
