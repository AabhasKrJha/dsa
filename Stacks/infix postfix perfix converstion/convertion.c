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
            stack_top_op = pop();
            while (isOperator(stack_top_op) && get_precedence(stack_top_op) >= get_precedence(infix_op)){
                output[index] = stack_top_op;
                index++;
                stack_top_op = pop();
            }
            push(stack_top_op);
            push(infix_op);
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
        printf("POSTFIX : %s", postfix);

    } else{
        printf("INVALID INFIX EXPRESSION");
    }

    free(infix_expression);
    free(stack);
    
    return 0;
}