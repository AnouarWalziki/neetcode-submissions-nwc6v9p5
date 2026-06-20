class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = 0;
        sort(piles.begin(), piles.end());
        for(int i = 0; i < piles.size(); i++){
            int t = 0;
            for(int j = piles.size() - 1; 0 <= j; j--){
                if(t > h){
                    break;
                } 
                t += piles[j] / piles[i] + !!(piles[j] % piles[i]);
            }
            if(t <= h){
                res = piles[i];
                break;
            }
        }
        return res;
    }
};
