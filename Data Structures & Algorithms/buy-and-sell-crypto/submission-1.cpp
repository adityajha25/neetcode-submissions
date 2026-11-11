class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int best=0;
        for (int i=1;i<prices.size();i++) {
            best = std::max(best, prices[i]-min);
            min = std::min(min, prices[i]);
        }
        return best;
        
    }
};
