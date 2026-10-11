class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for(int r = 0; r < prices.size(); r++){
            res = max(res, prices[r] - prices[l]);
            if(prices[r] < prices[l]){
                l = r;
            }
        }
        return res;
    }
};
