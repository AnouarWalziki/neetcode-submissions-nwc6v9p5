class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Count;
        for(char c : s1){
            s1Count[c]++;
        }

        int l = 0;
        unordered_map<char, int> currentCount;
        for(int r = 0; r < s2.size(); r++){
            currentCount[s2[r]]++;
            if((r - l + 1) == s1.size()){
                if(currentCount == s1Count){
                    return true;
                }
                currentCount[s2[l]]--;
                if(currentCount[s2[l]] <= 0){
                    currentCount.erase(s2[l]);
                }
                l++;
            }
        }
        return false;
    }
};
