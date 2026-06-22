class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int c = k;
        int res = 0;

        for(; r < s.size(); r++){
            cout << " l= " << l << " " << " r= " << r << " " <<  " c= " << c << endl;
            if(s[r] != s[l]){
                if(c > 0)
                    c--;
                else{
                    res = max(res, r - l);
                    cout << res << endl;
                    c = k;
                    l = r - k;
                    r--;
                }
            }
            cout << " l= " << l << " " << " r= " << r << " " <<  " c= " << c << endl;
            cout << endl;
        }

        return max(res, r - l);
    }
};
