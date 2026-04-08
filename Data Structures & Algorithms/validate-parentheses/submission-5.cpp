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
                if(!activeOpen.empty() && pairs[activeOpen.top()] == c)
                    activeOpen.pop();
                else
                    return false;
            }
        }
        if(!activeOpen.empty())
            return false;
        return true;
    }
};
