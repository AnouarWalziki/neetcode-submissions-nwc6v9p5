class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t res = 0;
        unordered_set<char> uniques;

        for(int r = 0; r < s.size(); r++){
            if(uniques.contains(s[r])){
                res = max(uniques.size(), res);
                uniques.clear();
            }

            uniques.insert(s[r]);
        }

        return max(uniques.size(), res);
    }
};
