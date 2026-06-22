class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int c = k;
        int res = 0;

        for(; r < s.size(); r++){
            if(s[r] != s[l]){
                if(c > 0)
                    c--;
                else{
                    res = max(res, r - l);
                    c = k;
                    l = r - k;
                }
            }
        }

        if(l > c)
            return max(res, r - l + c);
        return s.size();
    }
};
