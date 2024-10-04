#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[6];
    int temp;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (!(num[i] >= 0 && num[i] <= 9))
        {
            printf("You can only input one digit per line");
            exit(1);
        }
    }
    if (num[0] < 1)
    {
        printf("Your input is too small");
        exit(1);
    }
    temp = num[0];
    num[0] = num[4];
    num[4] = temp;
    temp = num[1];
    num[1] = num[3];
    num[3] = temp;
    num[5] = '\0';

    for (int i = 0; i < 5; i++)
    {
        if (num[i] != 0)
            break;
        num[i] = -1;
    }


    for (int i = 0; i < 5; i++)
    {
        if (num[i] != -1)
            printf("%d", num[i]);
    }


    return (0);
}