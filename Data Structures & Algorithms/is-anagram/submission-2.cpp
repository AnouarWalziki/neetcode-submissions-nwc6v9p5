class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        for(char current : s){
            auto pos = t.find(current);
            if(pos == std::string::npos)
                return false;
            t.erase(t.begin() + pos);
        }
        
        return true;
    }
};
