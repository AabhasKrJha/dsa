# New implementation

# change logs from the old implementation :
# [ENTER HERE]


class Convert:

    def __init__(self, max_len:int) -> None:
        self.max_len = max_len # capacity (max length) of the stack
        self.top = -1 # default top position of the pointer in the stack
        self.stack = [] # array implementation os stack used for operators handling
        self.output = [] # array for the output expression
        self. precedence = {
            "+" : 1, "-" : 1,
            "*" : 2, "/" : 2,
            "^" : 3
        }
    
    # ===== STACK OPERATIONS =====

    def isEmpty(self) -> bool:
        if self.top == -1:
            return True
        else:
            return False

    def push(self, operator:str) -> None:
        self.top += 1
        self.stack.append(operator)

    def pop(self) -> str:
        if not self.isEmpty():
            self.top = -1
            return self.stack.pop()
        else:
            return ""
    
    def peek(self) -> str:
        return self.stack[-1]

    # ===== PRESEDENCE CHECKING AND OPERATOR OPERATIONS =====
    
    def isOperand(self, charector:str) -> bool:
        if charector.isalpha() or charector.isdigit():
            return True
        else:
            return False
    
    def get_precedence(self, operator:str) -> int:
        return self.precedence[operator]

    # ===== CONVERTION FUNCTIONS =====

    def infix_to_postfix(self, infix:str) -> str:

        for charector in infix :

            # charector is alphabet or a digit
            if self.isOperand(charector):
                self.output.append(charector)
                print(self.output) #DEBUGGING----------------------
            
            elif charector == "(":
                self.push(charector)
                print(self.stack) #debugging --------------

            elif charector == ")":
                # if charector == ")" pop out elements from the stack and append the elememts to the output array 
                # when while popping and appending "(" is encountered pop it and discard both the parenthesis
                stack_top_op = self.stack[-1]
                while stack_top_op != "(":
                    print(stack_top_op) # debugging -----------
                    popped_op = self.stack.pop()
                    self.output.append(popped_op)
                    print(self.output) # debugging ----------------
                    stack_top_op = self.stack[-1]
                else:
                    self.stack.pop()
            
            else:
                # this else block works when an operator (+ - * / ^) is encountered
                infix_op = charector
                while not self.isEmpty():
                    try:
                        stack_top_op = self.peek()
                    except:
                        self.top = -1
                    if stack_top_op == "(":
                        self.push(infix_op)
                        print(self.stack) #debugging ---------------
                        break
                    else:
                        stack_top_op_precedence = self.get_precedence(stack_top_op)
                        infix_op_precedence = self.get_precedence(infix_op)
                        if stack_top_op_precedence < infix_op_precedence:
                            self.push(infix_op)
                            print(self.stack) #debidding ------------
                            break
                        else:
                            top = self.top
                            popped_op = self.pop()
                            self.output.append(popped_op)
                            print(self.output) # debugging _----------------
                            self.top = top
                else:
                    self.push(infix_op)
                    print(self.stack)#DEBUGGING----------------------
        try:
            while True:
                popped_op = self.stack.pop()
                self.output.append(popped_op)
                print(self.output) #debugging ------------
        except:
            pass
        
        print("".join(self.output))

# Driver Code
if __name__ == '__main__':
    infix = input("Enter infix expression : ")
    infix_obj = Convert(len(infix))
    infix_obj.infix_to_postfix(infix)