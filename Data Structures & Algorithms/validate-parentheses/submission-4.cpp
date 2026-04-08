class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs{{'(', ')'}, 
                                        {'[', ']'}, {'{', '}'}};

        stack<char> activeOpen;
        for(char c : s){
            if(pairs.contains(c)){
                activeOpen.push(c);
            }
            else {
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
