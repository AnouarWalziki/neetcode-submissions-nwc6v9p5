class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> opened{'(', '[', '{'};
        unordered_set<char> closed{')', ']', '}'};
        unordered_map<char, char> pairs{{'(', ')'}, 
                                        {'[', ']'}, {'{', '}'}};

        stack<char> activeOpen;
        for(char c : s){
            if(opened.contains(c)){
                activeOpen.push(c);
            }
            else if(closed.contains(c)){
                if(activeOpen.empty())
                    return false;
                char lastOpen = activeOpen.top();
                activeOpen.pop();
                if(pairs[lastOpen] != c)
                    return false;
            }
        }
        if(!activeOpen.empty())
            return false;
        return true;
    }
};
