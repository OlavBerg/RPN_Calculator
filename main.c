#include "stack.h"

#include <stdbool.h>
#include <stdio.h>


int main(void) {
    
    printf("Welcome to the RPN Calculator!\n");
    printf("Press 'q' to quit.\n\n");
    
    while(true) {
        printf("Enter expression to calculate: ");

        int num1;
        int num2;
        char op;
        scanf("%d %d %c", &num1, &num2, &op);

        int result;
        bool valid_op = true;
        switch(op) {
            case '+':
            result = num1 + num2;
            break;

            case '-':
            result = num1 - num2;
            break;

            case '*':
            result = num1 * num2;
            break;

            case '/':
            result = num1 / num2;
            break;

            default:
            valid_op = false;
        }

        if (valid_op) {
            printf("Result: %d\n", result);
        }
        else {
            printf("ERROR: Invalid operator!\n");
        }
    }

    return 0;
}