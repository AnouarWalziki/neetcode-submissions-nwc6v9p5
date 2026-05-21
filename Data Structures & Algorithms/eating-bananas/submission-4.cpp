class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;
        while(left <= right){
            int k = (left + right) / 2;
            int hours = 0;
            for(int p : piles){
                hours += ceil((double) p / k);
            }
            if(hours <= h){
                right = k - 1;
                res = k;
            }
            else if(hours > h){
                left = k + 1;
            }
        }
        return res;
    }
};