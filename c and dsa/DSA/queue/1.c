#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int is_empty(struct Stack *s) {
    return (s->top == -1);
}

int is_full(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(struct Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack is full. Cannot push further.\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty. Cannot pop further.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void merge_stacks(struct Stack *s1, struct Stack *s2) {
    while (!is_empty(s2)) {
        int item = pop(s2);
        push(s1, item);
    }
}

void display(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s1, s2;
    init(&s1);
    init(&s2);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);

    push(&s2, 4);
    push(&s2, 5);
    push(&s2, 6);

    printf("Stack 1: ");
    display(&s1);
    printf("Stack 2: ");
    display(&s2);

    merge_stacks(&s1, &s2);

    printf("After merging:\n");
    printf("Stack 1: ");
    display(&s1);
    printf("Stack 2: ");
    display(&s2); // Stack 2 should be empty after merging

    return 0;
}
