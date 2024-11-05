/*C program to implement the basic operations of Static
    Stack data structure.*/

#include <iostream>

/*Define Constants and Structures. 
5 is the maximum capacity of the stack.*/
#define MAX_SIZE 5
struct Stack {
    int data[MAX_SIZE];
    int top;
};


//Function prototypes for part b and c
bool isEmpty(Stack* aStack);
bool isFull(Stack* aStack);
void displayStack(Stack* aStack);
void push(Stack* aStack, int n);
int pop(Stack* aStack);

//bool isEmpty (Stack* aStack)
bool isEmpty(Stack* aStack) {
    return (aStack->top < 0);
}

//bool isFull (Stack* aStack);
bool isFull(Stack* aStack) {
	return (aStack->top >= MAX_SIZE - 1);
}
//void displayStack (Stack* aStack);
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

// Function to push an element onto the stack
void push(Stack* aStack, int n) {
    if (isFull(aStack)) {
        std::cout << "Stack is full.\n";
    }
    else {
        aStack->top++;
        aStack->data[aStack->top] = n;
    }
}

// Function to pop an element from the stack
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

/*Initialize the Stack in main()
We set aStack->top to -1, aka indicating that the stack is 
initially empty (no elements in it)*/
int main()
{
    Stack* aStack = new Stack;

	for (int k = 0; k <MAX_SIZE; k++) {
		aStack->data[k] = 0;
        aStack->top = -1;
	}

    //Calling isEmpty, isFull and displayStack
    std::cout << "Is the stack empty? " << (isEmpty(aStack) ? "Yes" : "No") << std::endl;
    std::cout << "Is the stack full? " << (isFull(aStack) ? "Yes" : "No") << std::endl;
    
    // Push elements 22, 33, and 44 to the stack
    push(aStack, 22);
    push(aStack, 33);
    push(aStack, 44);

    // Display the stack after pushing elements
    std::cout << "Stack elements after pushing 22, 33, and 44: ";
    displayStack(aStack);

    // Pop an element from the stack and display it
    std::cout << "Popped element: " << pop(aStack) << std::endl;

    // Display the stack after popping an element
    std::cout << "Stack elements after popping: ";
    displayStack(aStack);

    //Freeing the allocated memory, to avoid memory leaks. 
    delete aStack;
    return 0;
}

