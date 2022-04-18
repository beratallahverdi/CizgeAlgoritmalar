class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        char P[] = "()[]{}";

        for (auto ch: s) {
            // If any character other than a parenthesis, skip
            if (strchr(P, ch) == NULL) continue; 

            // When you see an opening parenthesis, push it to the stack
            if (ch == '(' or ch == '[' or ch == '{') {
                S.push(ch);

            } else {
                // OK. This is a closing parenthesis.
                if (S.empty()) return false;

                // Get the item at the top of the stack
                char top = S.top();
                S.pop();

                // Check for mismatch
                if      (top == '(' && ch != ')') return false;  // Mismatch
                else if (top == '[' && ch != ']') return false;  // Mismatch
                else if (top == '{' && ch != '}') return false;  // Mismatch
            } //end-else
        } //end-for

        return S.empty();
    } // end-isValid
};