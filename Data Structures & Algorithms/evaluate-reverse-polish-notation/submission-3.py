class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack= []

        for item in tokens:
            if item == "+":
                x=stack.pop()
                y=stack.pop()
                stack.append(x+y)
            elif item == "-":
                x=stack.pop()
                y=stack.pop()
                stack.append(y-x)
            elif item == "*":
                x=stack.pop()
                y=stack.pop()
                stack.append(y*x)
            elif item == "/":
                x=stack.pop()
                y=stack.pop()
                stack.append(int(y/x))
            else:
                stack.append(int(item))
        return stack[-1]