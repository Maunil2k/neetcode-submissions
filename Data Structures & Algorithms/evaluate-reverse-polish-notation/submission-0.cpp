class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = vals.top(); vals.pop();
                int a = vals.top(); vals.pop();

                if (token == "+") vals.push(a+b);
                else if (token == "-") vals.push(a-b);
                else if (token == "*") vals.push(a * b);
                else vals.push(a/b);
            }

            else vals.push(stoi(token));
        }

        return vals.top();
    }
};
