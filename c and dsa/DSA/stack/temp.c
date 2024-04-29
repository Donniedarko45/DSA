#include <stdio.h>
#define MAX_SIZE 100

// Initialize stack top
int top = -1;
// Array to store stack elements
int stack[MAX_SIZE];

// Check if stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Peek at the top element of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

// Main function
int main() {
    // Push elements onto the stack
    push(1);
    push(2);
    push(3);

    // Peek and pop elements
    printf("Top element: %d\n", peek()); // Output: 3
    printf("Popped element: %d\n", pop()); // Output: 3
    printf("Top element after pop: %d\n", peek()); // Output: 2

    return 0;
}