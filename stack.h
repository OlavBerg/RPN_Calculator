#ifndef STACK_H
#define STACK_H

#include <stddef.h>

void stack_push(int number);
int stack_pop(void);
size_t stack_size(void);
void stack_clear(void);

#endif // #ifndef STACK_H