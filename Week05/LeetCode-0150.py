class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        S = []
        for token in tokens:
            if len(token)==1 and not token.isdigit():
                operand2 = S.pop()
                operand1 = S.pop()
                                
                if token == "+":
                    result = operand1 + operand2
                elif token == "-":
                    result = operand1 - operand2
                elif token == "*":
                    result = operand1 * operand2
                else: # token == "/"
                    result = int(operand1 / operand2)                
                S.append(result)                
            else:
                S.append(int(token))
        return S[0]
