class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for(int n : piles){
            m = max(m, n);
        }        

        int left = 1;
        int mid = 0;
        int right = m;
        int res = 0;
        while(left <= right){
            mid = (left + right) / 2;
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
