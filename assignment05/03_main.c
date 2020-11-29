
int swapCharsAsm(int *x, int *y);

void swap_pointer(int **x, int **y)
{
    int * temp = *x;
    *x = *y;
    *y = temp;
}

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y =temp;

    if (*x == *y)
        return 0;
    else
        return 1;
}

int main()
{
    int x = 100;
    int y = 200;
    int result = -1;

    int *xPtr = &x;
    int *yPtr = &y;

    //swap(&x,&y);
    result = swapCharsAsm(&x,&y);
    swap_pointer(&xPtr,&yPtr);

  return 0;
}
