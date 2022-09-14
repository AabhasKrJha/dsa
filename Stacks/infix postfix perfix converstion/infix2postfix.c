#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// this program converts infix to postfix
// operators {"(",")","+","-","*","/","^"}

#define MAX 200
int stack[MAX];
int top = -1;
// push function
void push(char item){
    if (top >= MAX - 1){
        printf("stack is overflowing\n");
    }else{
        top++;             // -1+1=0 so now it allows us to add an item at the 0th position and will keep track of the yop most element
        stack[top] = item; // places an object on the stack top
        // doesn't return anything as the function type is void
    }
}
// pop functiom
char pop(){
    char item;
    if (top < 0){
        printf("stack is underflowing\n");
        exit(1);
    }else{
        item = stack[top];
        top = top - 1;
        return (item); // gets u the item that was poped could be an operator or bracked and all that is strored in x
        // note that this function has the type char so we have to store item in a char type variable
    }
}
int Operator(char symbol){
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'){
        return 1;
    }else{
        return 0;
    }
}
int OperatorPrecedence(char symbol){
    if (symbol == '^'){
        return 3; // returns 3 as a value to symbol
    }else if (symbol == '/' || symbol == '*'){
        return 2; // returns 2 as a value to symbol
    }else if (symbol == '+' || symbol == '-'){
        return 1; // returns 1 as a value to symbol
    }else{
        return 0;
    }
}
void Brackets(char infix[]){
    int i = 0, brac_count = 0;
    while (infix[i] != '\0'){
        if (infix[i] == '('){
            brac_count++;  //as this index increase it must be neutralized by the negative counter 
        }else if (infix[i] == ')'){
            brac_count--;   // this neutralizes the positive counter
            if (brac_count < 0)  
            /* if the counter has negavtive value then there must be more right brackets 
            than the left ones so the brackets are unbalanced*/
            {
                break;
            }
        }
        i++;  //helps in traversing through the string
    }

    if (brac_count == 0){
        printf("\n=================BRACKETS are Balanced================\n");
    }else{
        printf("\n********************BRACKETS are NOT Balanced****************\n");
        printf("\nPlease check the expression you have entered\n");
        exit(0);
    }
}
void Infix2Postfix(char infix[], char postfix[]){
    int i = 0, j = 0;
    char item = infix[i];
    char x;
    push('(');          // first step is pushing a left bracket into the stack
    strcat(infix, ")"); // appending a right bracket to the expression so that we can pop all elements at its encounter
    while (item != '\0'){
        if (item == '('){
            push(item);
        }
        else if (isdigit(item) || isalpha(item)){
            postfix[j] = item; // variables or digits go directly to the expression
            j++;
        }else if (Operator(item) == 1){
            x = pop(); /* NOW x has the stack top element.
            'item' hasn't been pushed to stack so we haven't poped the incoming operator
             if the while condition fails then we just push back x to the stack top  */
            while (Operator(x) == 1 && OperatorPrecedence(x) >= OperatorPrecedence(item)){
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }else if (item == ')'){
            x = pop();
            while (x != '('){
                postfix[j] = x;
                j++;
                x = pop();
            }
        }else{
            /*incoming symbol is not an expression nor an operator*/
            printf("\ninvalid expression!!\n");
            exit(1);
        }
        i++;
        item = infix[i];
        /*so first here item is updated and we take a character from infix
        expression and we increase i so that we can traverse the expression*/
    }
    postfix[j] = '\0';
}

int main(int argc, char const *argv[]){
    char infix_input[MAX], postfix_output[MAX];
    printf("\nEnter an INFIX EXPRESSION:\n");
    gets(infix_input);
    /*inputs a string and then are storing it in a array that we use later on*/

    Brackets(infix_input); /*CHECKING FOR BALANCED PARANTHESIS*/

    Infix2Postfix(infix_input, postfix_output);
    /*we call the function for the conversion. We give it 2 arguments one is an input
    string and the other is an empty string for the function can store its output*/

    printf("\nPostfix Expression is :");
    puts(postfix_output);

    printf("\n");
    return 0;
}


// CORRECTIONS :

// LINE 169 - use scanf("%s") instead of gets : gives the same output

// USE dynamic memory allocation (malloc and free) to make the program space complexity efficient, then use a for loop to traverse through the input infix expression

// use appropriate variables example : infix[i], for this use charector && for the function name brackets, use check_brackets

// use ternary operators in place of small if else statemets like in bracket checking

// use bool instead of void for bracker checker and check if true then do the converstion otherwise dont, do not use exit() in the brackets functions to stop program execution