class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++){
            if(freq[s[r]] > 0){
                res = max(res, r - l);
                while(l < r && freq[s[r]] > 0){
                    freq[s[l]]--;
                    l++;
                }
            }
            freq[s[r]]++;
        }
        return res;
    }
};
