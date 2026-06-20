class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)
            return false;
        
        int i = s.size() / 2;
        int j = i - 1;
        while(i < s.size()){ 
            if(s[j] == '(' && s[i] != ')')
                return false;
            if(s[j] == '{' && s[i] != '}')
                return false;
            if(s[j] == '[' && s[i] != ']')
                return false;
            i++;
            j--;
        }
        return true;
    }
};
