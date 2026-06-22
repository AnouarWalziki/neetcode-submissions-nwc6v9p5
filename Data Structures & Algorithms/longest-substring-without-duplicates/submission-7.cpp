class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<char> chars;
        for (int r = 0; r < s.size(); r++){
            while(chars.contains(s[r])){
                chars.erase(s[l]);
                l++;
            }
            res = max(res, r - l + 1);
            chars.insert(s[r]);
        }

        return res;
    }
};
