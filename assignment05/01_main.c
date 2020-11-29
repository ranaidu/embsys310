
void swap_pointer(int **x, int **y)
{
    int * temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y =temp;
}

int main()
{
    int x = 100;
    int y = 200;

    int *xPtr = &x;
    int *yPtr = &y;

    swap(&x,&y);
    swap_pointer(&xPtr,&yPtr);

  return 0;
}
