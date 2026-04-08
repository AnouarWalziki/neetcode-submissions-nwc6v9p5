class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> validOps{"+", "-", "*", "/"};
        stack<string> operators;
        stack<int> nums;

        for (int i = 0; i < tokens.size(); i++){
            if(!validOps.contains(tokens[i]))
                nums.push(stoi(tokens[i]));
            else {
                int rightSide = nums.top();
                nums.pop();
                int leftSide = nums.top();
                nums.pop();
                int result = 0;
                if(tokens[i] == "+")
                    result = leftSide + rightSide;
                else if(tokens[i] == "-")
                    result = leftSide - rightSide;
                else if(tokens[i] == "*")
                    result = leftSide * rightSide;
                else if(tokens[i] == "/")
                    result = leftSide / rightSide;
                nums.push(result);
            }
        }
        return nums.top();
    }
};
