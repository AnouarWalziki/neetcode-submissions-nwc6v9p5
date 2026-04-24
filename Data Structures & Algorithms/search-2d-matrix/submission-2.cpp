class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m =  matrix.size();
        int l = 0;
        int r = n * m - 1;

        while(l <= r){
            int mid = (l + r) / 2;
            int m1 = mid / n;
            int m2 = mid % n;
            cout << "m " << mid << " m1 " << m1 << " m2 " << m2 << endl;
            cout << "l " << l << " r " << r << endl;
            if(target < matrix[m1][m2]){
                r = mid - 1;
            }
            else if (target > matrix[m1][m2]){
                l = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
