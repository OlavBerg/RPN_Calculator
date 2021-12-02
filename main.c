#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main(void) {
    
    printf("Welcome to the RPN Calculator!\n");
    printf("Press 'q' to quit.\n\n");

    while (true) {
        printf("Enter expression to calculate: ");

        char num_str[16];
        size_t num_str_ctr = 0;
        bool num_flag = false;

        while (true) {
            char c = getchar();

            if (c == '\n') {
                break;
            }

            if (is_digit(c)) {
                num_flag = true;
                num_str[num_str_ctr++] = c;
                continue;
            }

            if (c == ' ') {
                if (num_flag) {
                    num_str[num_str_ctr] = '\0';
                    num_str_ctr = 0;
                    stack_push(atoi(num_str));
                    num_flag = false;
                }
                continue;
            }

            int num2 = stack_pop();
            int num1 = stack_pop();
            int result;

            switch(c) {
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
            }

            stack_push(result);
        }

        printf("Result: %d\n", stack_pop());
    }
}