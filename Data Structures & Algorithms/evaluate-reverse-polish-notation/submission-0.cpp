class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;

        for (int i=0;i<tokens.size();i++) {
            std::string curr = tokens[i];
            if (curr=="+") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op1+op2);
            } else if (curr=="-") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(op1-op2);
            } else if (curr=="*") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(op1*op2);
            } else if (curr=="/") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                int x=op1/op2;
                s.push(x);
            } else {
                s.push(std::stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
