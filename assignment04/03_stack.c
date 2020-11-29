#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointers to queue elements for adding and retrieving
int* pushPtr;
int* popPtr;

// LIFO Stack is Empty if pushPtr==popPtr;
// LIFO Stack is Full if pushPtr+1 > Address of last element in the queue;

// Initialize internals of the queue
void stack_init(void)
{
    pushPtr = 0;
    popPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = '\0';
    }
}

bool IsStackFull(void)
{
    if (pushPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full
        return 1;
    }
}

bool IsStackEmpty(void)
{
    if (popPtr == pushPtr+1)
    {
        // stack is empty
        return 1;
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int push(int data)
{
    if( IsStackFull() == 1)
    {
        return -1;
    }

    /*if (popPtr == pushPtr+1)
    {
        //queue is empty
        return -1;
    }*/
    if( IsStackEmpty() == 1 )
    {
        return -1;
    }

    if (popPtr == 0)
    {
        popPtr = &StackStore[0];
    }

    if (pushPtr == 0 || pushPtr == &StackStore[STACK_SIZE-1])
    {
        pushPtr = &StackStore[0];
    }
    else
    {
        pushPtr++;
    }

    *pushPtr = data;

     popPtr = pushPtr;
    return 0;
}

// Get data from queue
// If queue is empty return error
// Otherwise return success
int pop(void)
{

    if( popPtr == 0 )
    {
        return -1;
    }

    int data = *popPtr;
    *popPtr = 0;

    if (popPtr == 0)
    {
        popPtr = 0;
    }
    else
    {
        pushPtr = -- popPtr;
    }

    return data;
}
