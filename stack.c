#include "stack.h"

#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

Node *head = NULL;

void stack_push(int number) {
    Node *new = malloc(sizeof(Node));
    new->number = number;
    new->next = head;
    head = new; 
}

int stack_pop(void) {
    int number = head->number;
    
    Node *head_old = head;
    head = head->next;
    free(head_old);

    return number;
}