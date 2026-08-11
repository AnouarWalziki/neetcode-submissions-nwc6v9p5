class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26,0);
        for(int i = 0; i < s1.size(); i++){
            s1Count[(int)s1[i] - (int)'a']++;
            s2Count[(int)s2[i] - (int)'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(s1Count[i] == s2Count[i]){
                matches++;
            }
        }

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            if(matches == 26){
                return true;
            }

            int index = (int)s2[r] - (int)'a';
            s2Count[index]++;
            if(s1Count[index] == s2Count[index]){
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]){
                matches--;
            }

            index = (int)s2[l] - (int)'a';
            s2Count[index]--;
            if(s1Count[index] == s2Count[index]){
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]){
                matches--;
            }
            l++;
        }
        return false;
    }
};
