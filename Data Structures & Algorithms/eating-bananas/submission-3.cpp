class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int t = 0;
            for(int j = piles.size() - 1; 0 <= j; j--){
                if(t > h){
                    break;
                } 
                t += ceil((double) piles[j] / mid);
            }
            cout << "t " << t << " mid " << mid << endl;
            if(t <= h){
                right = mid - 1;
                res = mid;
            }
            else if(t > h){
                left = mid + 1;
            }
        }
        return res;
    }
};
