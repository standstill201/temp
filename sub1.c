#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    srand((unsigned)time(NULL));

    int n = (rand() % 11) + 10;
    int arr[20];

    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <20; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("n = %d\n", n);
    for (int j = n - 1; j >= 0; j--)
    {
        printf("f(%d) = %d  ", j + 1, arr[j]);
        // f(10)=55 f(9)=34 f(8)=21 ........ f(2)=1 f(1)=1 
    }
}