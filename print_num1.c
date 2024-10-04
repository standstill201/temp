#include <stdio.h>
#include <stdlib.h>

int main()
{
    char num[6];
    char temp;

    scanf("%c%c%c%c%c", &num[0],&num[1],&num[2],&num[3],&num[4]);

    for (int i = 0; i < 5; i++)
    {
        if (!(num[i] >= 48 && num[i] <= 57))
        {
            printf("Your input is not a number");
            exit(1);
        }
    }
    if (num[0] < '1')
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
    printf("%d\n", atoi(num));


    return (0);
}