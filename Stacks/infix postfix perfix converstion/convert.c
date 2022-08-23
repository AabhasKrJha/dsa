#include <stdio.h>
#include <stdlib.h> // to use free() fxn with calloc
#include <stdbool.h> // to use bool fxns
#include <string.h>

// ======= STACK OPERATIONS =======

// stack implementation using structure and array
struct Stack{
    int top; // position of pointer in the array
    unsigned capacity; // carries zero or a positive numbers
    int* stack; // stack implementation using array
};

//fxn to create a stack

// ======= PRESEDENCE CHECKING AND OPERATOR OPERATIONS =======

// fxn to get precedence of operators
// JSON -> {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
int get_preference(char operator){
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
    if (('a' <= charector <= 'z') || ('A' <= charector <= 'Z')){
        // checkiing if the charector is a letter
        return true;
    } else if (0 <= (int)(charector - '0') <= 9){
        // checking is the charector is a digit by typecasting ascii values
        // (int)('1' - '0') = 1
        return true;
    } else{
        return false;
    }
}

char* infix;

int main(){
    infix = calloc(100, sizeof(char));
    scanf("%s", infix);
    printf("%s", infix);
    free(infix);
    return 0;
}



// changelogs :

// [ENTER HERE]
