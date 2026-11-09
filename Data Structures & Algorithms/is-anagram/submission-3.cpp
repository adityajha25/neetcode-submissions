class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int counts[26] = {0};
        int nonzero=0;

        for (int i=0;i<s.size();i++) {

            if (counts[s[i] - 'a'] == -1) {
                nonzero-=1;
            } else if (counts[s[i] - 'a'] == 0) {
                nonzero+=1;
            }

            counts[s[i] - 'a']++;

            if (counts[t[i] - 'a'] == 1) {
                nonzero-=1;
            } else if (counts[t[i] - 'a'] ==0) {
                nonzero+=1;
            }
            counts[t[i] - 'a']--;
        }

        return nonzero==0;
    }
};
