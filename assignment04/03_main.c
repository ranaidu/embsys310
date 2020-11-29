#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;

    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    stack_init();

    // Act:
    result1 = pop();

    // Assert:
    assert(-1 == result1);
    assert(100 == testInt);

    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 120;
    stack_init();

    // Act:
    result1 = push(52);
    result2 = pop();

    // Assert:
    assert(0 == result1);
    assert(52 == result2);


    // *******************************************************************
    // Test3: Fill queue, then get all items.
    // *******************************************************************
    // Arrange:
    stack_init();

    // Act:
    push(22);
    push(52);
    push(78);

    // Assert:
    assert(78 == pop());

    assert(52 == pop());

    assert(22 == pop());


    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    stack_init();

    // Act:
    push(22);
    push(54);
    push(89);

    // Assert:
    assert(-1 == push(120));

    assert(89 == pop());

    assert(54 == pop());


    assert(22 == pop());



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    stack_init();

    // Act:
    push(22);
    push(54);
    push(89);

    // Assert:
    assert(89 == pop());

    assert(0 == push(98));

    assert(98 == pop());


    assert(54 == pop());


    assert(22 == pop());


    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    stack_init();

    // Act:
    push(22);
    push(54);
    push(89);

    // Assert:
    assert(89 == pop());

    assert(54 == pop());

    assert(22 == pop());

    assert(0 == push(1));
    assert(0 == push(2));
    assert(0 == push(3));

    assert(-1 == push(4));

    assert(3 == pop());

    assert(2 == pop());

    assert(1 == pop());

    return 0;
}
