class Solution {
public:
    bool isAnagram(string s, string t) {
        int sum1 = 0;
        for(char current : s){
            sum1 += current;
        }
        int sum2 = 0;
        for(char current : t){
            sum2 += current;
        }
        return sum1 == sum2;
    }
};
