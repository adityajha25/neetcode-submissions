class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int> seen = {};
        int count=0;
        int start=0;
        for (int i=0;i<s.size();i++) {
            while(seen.contains(s[i])) {
                seen.erase(s[start]);
                start++;
            }
            seen.insert(s[i]);
            count = std::max(count, i-start+1);
        }
        return count;
    }
};
