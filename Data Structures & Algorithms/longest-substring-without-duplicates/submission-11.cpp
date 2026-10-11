class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniques;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++){
            while(uniques.contains(s[r])){
                uniques.erase(s[l]);
                l++;
            }
            uniques.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
