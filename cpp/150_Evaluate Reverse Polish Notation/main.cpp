/* 150. Evaluate Reverse Polish Notation
Medium

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
 */

// Runtime: 13 ms, faster than 84.85% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 12.2 MB, less than 51.95% of C++ online submissions for Evaluate Reverse Polish Notation.


# include <iostream>
# include <stack>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> operand_stack;
        long long first, second;
        for (auto e: tokens) {
            if (e == "+" || e == "-" || e == "*" || e == "/") {
                second = operand_stack.top(); operand_stack.pop();
                first = operand_stack.top(); operand_stack.pop();
                if (e == "+") first += second;
                else if (e == "-") first -= second;
                else if (e == "*") first *= second;
                else if (e == "/") first /= second;

                operand_stack.push(first);
            }
            else operand_stack.push(stoi(e));
        }
        return operand_stack.top();
    }
};

int main() {
    // Inputs.
    // vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens = {"4","13","5","/","+"};

    // Solution.
    Solution solution;
    cout << solution.evalRPN(tokens) << endl;

    return 0;
}
