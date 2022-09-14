#include <stdio.h>
#include <stdlib.h> // to use the maloc() and free() function
#include <stdbool.h> // to use the bool datatype (true and false)
#include <string.h> // for string operations (here strlen)
#include <ctype.h> // for isalpha() and isdigit() functions

// ===== OPERATIONAL VARIABLES =====

char* infix_expression;
char* output; // to store the postfix or prefix expression

char* stack; // stack used for convertion operations
int capacity;
int top = -1;

char operators[5] = "+-*/^";

// ===== STACK OPERATIONS =====

void push(int charector){
    top++;
    stack[top] = charector;
}

char pop(){
    char charector = stack[top];
    top--;
    return charector;
}

// ===== PRESEDENCE CHECKING AND OPERATOR OPERATIONS =====

int get_precedence(char operator){
    switch (operator){
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

// fxn to find if a charector is an operand or not
bool isOperand(char charector){
    return (isdigit(charector) || isalpha(charector)) ? true : false;
}

bool isOperator(char charector){
    char* found = strchr(operators, charector);
    return (found == NULL) ? false : true;
}

// ===== CONVERSTION FUNCTIONS =====

bool check_bracket_order(char* infix, int capacity){
    int brackets_balance = 0;
    for (int position = 0; position < capacity; position++){
        char bracket = infix[position];
        if (bracket == '('){
            brackets_balance++; // symolises the number of openning brackets
        } else if (bracket == ')'){
            brackets_balance--; // neutalises an open bracket whenever a closed bracket is encountered
        }
    }
    return (brackets_balance == 0) ? true : false;
}

char* infix_to_postfix(){

    int index = 0;
    char stack_top_op;

    for (int position = 0; position < capacity; position++){
        // getting what charector to analyse in the infix expression
        char charector = infix_expression[position];
        // if charector is an operator
        if (isOperator(charector)){
            char infix_op = charector;
            int infix_op_precedence = get_precedence(infix_op);
            stack_top_op = pop();
            if (stack_top_op == '\0'){
                push(infix_op);
            }
            while (stack_top_op != '\0'){
                if (stack_top_op == '('){
                    push(infix_op);
                }else{
                    push(stack_top_op);
                    int stack_top_op_precedence = get_precedence(stack_top_op);
                    if (stack_top_op_precedence < infix_op_precedence){
                        push(infix_op);
                    } else{
                        stack_top_op = pop();
                        output[index] = stack_top_op;
                        index++;

                    }
                }
                stack_top_op = pop();
            }
        } 
        // if charector is an operand we append it to the output expresssion
        else if(isOperand(charector)){
            output[index] = charector;
            index++;
        } 
        // if charector is an open paranthesis we push it to the stack
        else if (charector == '('){
            push(charector);
        } 
        // if charctor is a closing paranthesis we pop all operators and append it the the output expression till an open paranthesis is encountered
        else if (charector == ')'){
            char popped = pop();
            while (popped != '('){
                output[index] = popped;
                index++;
                popped = pop();
            }
        }
    }
    while (stack_top_op != '\0'){
        output[index] = stack_top_op;
        index++;
    }
    return output;
}

char* reverse(char* str){  
    int len = strlen(str);
    char temp; 
    for (int index = 0; index < len/2; index++){  
        temp = str[index];  
        str[index] = str[len - index - 1];  
        str[len - index - 1] = temp;  
    }
    return str;
}

char* replace_brackets(char* str){
    int len = strlen(str);
    for(int index = 0; index < len; index++){
        char charector = str[index];
        if (charector == '('){
            str[index] = ')';
        } else if (charector == ')'){
            str[index] = '(';
        }
    }
    return str;
}

char* infix_to_prefix(){
    char* infix_rev = reverse(infix_expression);
    infix_rev = replace_brackets(infix_rev);
    char* prefix_rev = infix_to_postfix();
    char* prefix = reverse(prefix_rev);
    return prefix;
}

// ===== DRIVER CODE =====

int main(){
    
    int min_capacity = 3; // min capacity of infix expression must be 3 because there must be atleast one operator bet
    infix_expression = malloc(min_capacity * sizeof(char));
    scanf("%s", infix_expression);

    capacity  = strlen(infix_expression);
    stack = (char*) malloc(capacity * sizeof(char));
    output = (char*) malloc(capacity * sizeof(char));

    bool bracets_in_order = check_bracket_order(infix_expression, capacity);

    if (bracets_in_order){
        char* postfix = infix_to_postfix();
        char* prefix = infix_to_prefix();
        printf("POSTFIX : %s \n", postfix);
        printf("PREFIX : %s", prefix);

    } else{
        printf("INVALID INFIX EXPRESSION");
    }

    free(infix_expression);
    free(stack);
    
    return 0;
}