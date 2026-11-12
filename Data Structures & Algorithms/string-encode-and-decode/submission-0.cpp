class Solution {
public:

    string encode(vector<string>& strs) {
        std::string final = "";
        for (int i=0;i<strs.size();i++) {
            final+='|';
            final+=to_string(strs[i].size());
            final+='|';
            final+=strs[i];
        }
        return final;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i=0;i<s.size();i++) {
            if (s[i]-'|'==0) {
                i++;
                std::string len = "";
                
                while (s[i]-'|' != 0) {
                    len+=s[i];
                    i+=1;
                }
                int length = stoi(len);
                i++;
                std::string curr="";
                for (int j=i;j<i+length;j++) {
                    curr+=s[j];
                }
                ans.push_back(curr);
                i+=length-1;
            }
        }
        return ans;

    }
};
