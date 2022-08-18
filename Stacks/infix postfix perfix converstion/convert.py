infix = input("Enter infix expression : ")
operators = "+ - * / ^"

def get_precedence(operator):
    precedence = {"+-" : 3, "*/" : 2, "^" : 1}
    for i in precedence:
        if operator in i:
            return precedence[i]

def infix_to_postfix(infix):

    global operators

    stack = []
    postfix = []

    for element in infix:

        if element in operators:

            if len(stack) == 0:
                stack.append(element)

            else:

                exp_op_precedence = get_precedence(element)

                for top in range(len(stack) - 1, -1, -1):

                    stack_op = stack[top]
                    stack_op_presedence = get_precedence(stack_op)

                    if stack_op_presedence > exp_op_precedence:
                        stack.append(element)
                        break

                    else:
                        pop_op = stack.pop()
                        postfix.append(pop_op)
                        if len(stack) == 0:
                            stack.append(element)
                            break
        else:
            postfix.append(element)

    for top in range(len(stack) - 1, -1, -1):
        operator = stack[top]
        postfix.append(operator)
    
    return "".join(postfix)

print(infix_to_postfix(infix))