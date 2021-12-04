#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void clear_stdin(void) {
    while (getchar() != '\n');
}

static bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main(void) {
    
    printf("Welcome to the RPN Calculator!\n");
    printf("Type 'q' to quit.\n\n");
    bool running = true;

    while (true) {
        char num_str[16];
        size_t num_str_ctr = 0;
        bool num_flag = false;
        bool valid_expression = true;

        printf("Enter expression to calculate: ");

        while (true) {
            char c = getchar();

            if (c == 'q' && stack_size() == 0) {
                running = false;
                clear_stdin();
                break;
            }

            if (c == '\n') {
                break;
            }

            if (is_digit(c)) {
                if (!num_flag) {
                    num_flag = true;
                }
                num_str[num_str_ctr] = c;
                continue;
            }

            if (num_flag) {
                stack_push(atoi(num_str));
                num_str_ctr = 0;
                num_flag = false;
                continue;
            }

            if (c == ' ') {
                continue;
            }

            // c is an operator

            if (stack_size() < 2) {
                valid_expression = false;
                clear_stdin();
                break;
            }

            int num2 = stack_pop();
            int num1 = stack_pop();
            int result;

            bool valid_operator = true;
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

                default:
                valid_operator = false;
            }

            if (!valid_operator) {
                valid_expression = false;
                clear_stdin();
                break;
            }

            stack_push(result);
        }

        if (!running) {
            break;
        }

        if (stack_size() != 1) {
            valid_expression = false;
        }

        if (!valid_expression) {
            printf("ERROR: Invalid expression!\n");
            stack_clear();
            continue;
        }

        printf("Result: %d\n", stack_pop());
    }

    printf("Quitting the calculator.\n");
    return 0;
}