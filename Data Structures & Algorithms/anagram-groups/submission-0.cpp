class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> anagrams;

        for (int i=0;i<strs.size();i++) {
            std::array<int, 26> counts = {};
            for (int j=0;j<strs[i].size();j++) {
                counts[strs[i][j] - 'a']+=1;
            }
            std::string a = hash(counts);
            anagrams[a].push_back(strs[i]);
        }

        vector<vector<string>> answer;

        for (auto& [key, value] : anagrams) {
            vector<string> local;
            for (int i=0;i<value.size();i++) {
                local.push_back(value[i]);
            }
            answer.push_back(local);
        }

        return answer;

        
    }

    std::string hash(std::array<int,26>& frequencies) {
        std::string ans = "";
        for (int i=0;i<frequencies.size();i++){
            ans.push_back(frequencies[i]);
            ans.push_back('@');
        }
        return ans;
    }
};
