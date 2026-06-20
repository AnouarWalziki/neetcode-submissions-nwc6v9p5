class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int b = 0;

        for(int i = 1; i < prices.size(); i++){
            int p = prices[i] - prices[b];
            res = max(p, res);
            if(prices[i] < prices[b]){
                b = i;
            }
        }

        return res;
    }
};
