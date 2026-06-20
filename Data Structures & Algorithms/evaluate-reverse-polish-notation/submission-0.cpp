class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> validOps{"+", "-", "*", "/"};
        stack<string> operators;
        for(int i = tokens.size() - 1; i >= 0; i--){
            if(validOps.contains(tokens[i]))
                operators.push(tokens[i]);
        }

        int result = stoi(tokens[0]);
        if(operators.empty())
            return result;

        for (int i = 1; i < tokens.size(); i++){
            if(validOps.contains(tokens[i]))
                continue;
            auto currentOp = operators.top();
            operators.pop();
            int val = stoi(tokens[i]);
            if(currentOp == "+")
                result += val;
            else if(currentOp == "-")
                result -= val;
            else if(currentOp == "*")
                result *= val;
            else if(currentOp == "/")
                result /= val;
        }
        return result;
    }
};
