class Solution {
public:
    ///----------------------------------------------------------
    /// Evaluate using a stack
    ///
    int evalRPN(vector<string>& tokens) {
        stack<int> S;

        for (auto token: tokens){
            if (token.length() == 1 && !isdigit(token[0])){
                // If this is an operator, then pop two operands
                // off the stack and apply the operator
                int operand2 = S.top(); S.pop();
                int operand1 = S.top(); S.pop();
                int result;

                switch(token[0]){
                    case '+': result = operand1 + operand2;
                        break;
                    case '-': result = operand1 - operand2;
                        break;
                    case '*': result = operand1 * operand2;
                        break;
                    case '/': result = operand1 / operand2;
                        break;
                } //end-switch

                S.push(result);

            } else {
                S.push(std::stoi(token));  // Convert the number in string to an integer
            } //end-else
        } //end-for

        return S.top();
    } // end-evalRPN
};