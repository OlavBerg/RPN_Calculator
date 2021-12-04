#include "stack.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

Node *head = NULL;
size_t size = 0;

void stack_push(int number) {
    Node *new = malloc(sizeof(Node));
    new->number = number;
    new->next = head;
    head = new;
    size++; 
}

int stack_pop(void) {
    int number = head->number;
    
    Node *head_old = head;
    head = head->next;
    free(head_old);
    size--;

    return number;
}

size_t stack_size(void) {
    return size;
}

void stack_clear(void) {
    while (head) {
        Node *head_old = head;
        head = head->next;
        free(head_old);
    }
    size = 0;
}

bool stack_empty(void) {
    return size == 0;
}