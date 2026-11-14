class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        dp.push_back(triangle.back());

        for (int i=triangle.size()-2; i>=0; i--) {
            for (int j=0;j<triangle[i].size();j++) {
                dp[0][j] = std::min(dp[0][j], dp[0][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};