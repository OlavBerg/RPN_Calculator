#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

void stack_push(int number);
int stack_pop(void);
size_t stack_size(void);
void stack_clear(void);
bool stack_empty(void);

#endif // #ifndef STACK_H