#include <iostream>

#define MAX_SIZE 5

struct Stack {
    int data[MAX_SIZE];
    int top;
};

bool isEmpty(Stack* aStack);
bool isFull(Stack* aStack);
void displayStack(Stack* aStack);
void push(Stack* aStack, int n);
int pop(Stack* aStack);
int stackSize(Stack* aStack);

bool isEmpty(Stack* aStack) {
    return (aStack->top < 0);
}

bool isFull(Stack* aStack) {
    return (aStack->top >= MAX_SIZE - 1);
}

void displayStack(Stack* aStack) {
    if (isEmpty(aStack)) {
        std::cout << "Stack is empty.\n";
    }
    else {
        for (int k = 0; k <= aStack->top; k++) {
            std::cout << aStack->data[k] << " ";
        }
        std::cout << std::endl;
    }
}

void push(Stack* aStack, int n) {
    if (isFull(aStack)) {
        std::cout << "Stack is full.\n";
    }
    else {
        aStack->top++;
        aStack->data[aStack->top] = n;
    }
}

int pop(Stack* aStack) {
    int data = -1;
    if (isEmpty(aStack)) {
        std::cout << "Stack is empty.\n";
    }
    else {
        data = aStack->data[aStack->top];
        aStack->top--;
    }
    return data;
}

int stackSize(Stack* aStack) {
    return (aStack->top + 1);
}

int main() {
    Stack* aStack = new Stack;
    aStack->top = -1;

    push(aStack, 22);
    push(aStack, 33);
    push(aStack, 44);

    std::cout << "Stack elements after pushing 22, 33, and 44: ";
    displayStack(aStack);

    std::cout << "Current stack size: " << stackSize(aStack) << std::endl;

    std::cout << "Popped element: " << pop(aStack) << std::endl;

    std::cout << "Stack elements after popping: ";
    displayStack(aStack);

    std::cout << "Current stack size after popping: " << stackSize(aStack) << std::endl;

    delete aStack;
    return 0;
}
