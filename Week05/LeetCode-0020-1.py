class Solution:
    def isValid(self, s: str) -> bool:
        S = []  # Emulate a stack with a list
        P = "()[]{}"

        for ch in s:
            # If any character other than a parenthesis, skip
            if ch not in P: continue

            # When you see an opening parenthesis, push it to the stack
            if ch == '(' or ch == '[' or ch == '{':
                S.append(ch)
            else:
                # OK. This is a closing parenthesis.
                if len(S) == 0: return False

                # Get the item at the top of the stack
                top = S[-1]
                S.pop()

                # Check for mismatch
                if   top == '(' and ch != ')': return False  # Mismatch
                elif top == '[' and ch != ']': return False  # Mismatch
                elif top == '{' and ch != '}': return False  # Mismatch
        return len(S) == 0
        