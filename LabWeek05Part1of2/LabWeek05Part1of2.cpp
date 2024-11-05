// LabWeek05Part1of2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX_SIZE 5
struct Stack {
    int data[MAX_SIZE];
    int top;
};

int main()
{
    //C program to implement the basic operations of Static Stack data structure.
    
    //Declare and initialize an empty stack using Array. 

    Stack* aStack = new Stack;

	for (int k = 0; k <MAX_SIZE; k++) {
		aStack->data[k] = 0;
        aStack->top = -1;
	}

    //Freeing the allocated memory, to avoid memory leaks. 
    delete aStack;
    return 0;
}

