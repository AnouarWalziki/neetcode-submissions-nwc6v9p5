class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = 0;
        sort(piles.begin(), piles.end());
        int max = piles[piles.size() - 1];
        for(int i = 1; i <= max; i++){ 
            int t = 0;
            for(int j = piles.size() - 1; 0 <= j; j--){
                if(t > h){
                    break;
                } 
                t += piles[j] / i + !!(piles[j] % i);
            }
            if(t <= h){
                res = i;
                break;
            }
        }
        return res;
    }
};
