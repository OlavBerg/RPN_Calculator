#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void clear_stdin(void) {
    while (getchar() != '\n');
}

static bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main(void) {
    
    printf("Welcome to the RPN Calculator!\n");
    printf("Press 'q' to quit.\n\n");

    
    while (true) {
        bool running = true;
        bool valid_input = true;

        printf("Enter expression to calculate: ");

        char num_str[16];
        size_t num_str_ctr = 0;
        bool num_flag = false;

        
        while (true) {
            char c = getchar();

            if (c == 'q') {
                running = false;
                break;
            }

            if (c == '\n') {
                break;
            }

            if (is_digit(c)) {
                if (!num_flag) {
                    num_flag = true;
                }
                num_str[num_str_ctr++] = c;
                continue;
            }

            if (num_flag) {
                num_str[num_str_ctr] = '\0';
                num_str_ctr = 0;
                stack_push(atoi(num_str));
                num_flag = false;
            }

            if (c == ' ') {
                continue;
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
                valid_input = false;
                break;
            }

            stack_push(result);
        }

        if (!running) {
            printf("Quitting the calculator.\n");
            break;
        }

        if (!valid_input) {
            printf("ERROR: Invalid input\n");
            clear_stdin();
            continue;
        }

        printf("Result: %d\n", stack_pop());
    }
}