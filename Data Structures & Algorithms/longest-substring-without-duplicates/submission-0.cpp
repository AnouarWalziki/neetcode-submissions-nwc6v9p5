class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t res = 0;
        int l = 0;
        unordered_set<char> uniques;

        for(int r = 0; r < s.size(); r++){
            if(uniques.contains(s[r])){
                res = max(uniques.size(), res);
                uniques.clear();
                l = r;
            }

            uniques.insert(s[r]);
        }
        return res;
    }
};
