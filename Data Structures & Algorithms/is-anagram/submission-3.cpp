class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        std::unordered_map<int,int> occur;
        for(char current : s){
            occur[current] += 1;
        }
        for(char current : t){
            occur[current] -= 1;
            if(occur[current] < 0)
                return false;
        }
        
        return true;
    }
};
