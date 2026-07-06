class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() <= k)
            return s.size();

        unordered_map<char, int> occurs;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            occurs[s[r]]++;
            char cRp = s[r];
            int maxFrq = occurs[cRp];
            for(auto [c, v] : occurs){
                if(maxFrq < v){
                    maxFrq = v;
                    cRp = c;
                }
            }

            int length = r - l + 1;
            cout << length << endl;
            while(l <= r && (length - occurs[cRp]) > k){
                occurs[s[l]]--;
                length--;
                l++;
                maxFrq = occurs[cRp];
                for(auto [c, v] : occurs){
                    if(maxFrq < v){
                        maxFrq = v;
                        cRp = c;
                    }
                }
            }
            res = max(res, length);
        }
        return res;
    }
};
