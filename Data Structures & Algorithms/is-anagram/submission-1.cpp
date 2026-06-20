class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        for(char current : s){
            auto it = t.find(current);
            if(it == std::string::npos)
                return false;
            t.erase(it);
        }
        
        return true;
    }
};
