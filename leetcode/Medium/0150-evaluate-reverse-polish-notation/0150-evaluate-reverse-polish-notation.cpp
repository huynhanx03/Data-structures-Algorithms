/*
 Problem: 150. Evaluate Reverse Polish Notation
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.2 MB (15.37%)
 Tags: Array, Math, Stack
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<double> st;

        for (auto& x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = 0;

                if (x == "+") {
                    result = num1 + num2;
                } else if (x == "-") {
                    result = num2 - num1;
                } else if (x == "*") {
                    result = num1 * num2;
                } else if (x == "/") {
                    result = num2 / num1;
                }

                st.push(result);

            } else {
                st.push(stoi(x));
            }
        }

        return st.top();
    }
};