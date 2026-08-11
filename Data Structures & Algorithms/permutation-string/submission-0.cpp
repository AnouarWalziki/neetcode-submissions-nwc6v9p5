class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Count;
        for(char c : s1){
            s1Count[c]++;
        }

        for(int i = 0; i < s2.size(); i++){
            unordered_map<char, int> currentCount;
            for(int j = 0; j < s1.size(); j++){
                if((j + i) >= s2.size()){
                    break;
                }
                currentCount[s2[j + i]]++;
            }

            if(currentCount == s1Count){
                return true;
            }
        }
        return false;
    }
};
