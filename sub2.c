#include <stdio.h>

int main()
{
    float rate[1000];
    int rank[4];
    int middle, final;
    int index = 0;
    float sum = 0.0f;
    int max = 0;

    while (scanf(" %d %d", &middle, &final) != EOF)
    {
        rate[index] = (final - middle) * 1.0 / middle * 100;
        if (rate[index] < 0)
            rank[0] += 1;
        else if (rate[index] <= 50)
            rank[1] += 1;
        else if (rate[index] <= 100)
            rank[2] += 1;
        else
            rank[3] += 1;
        sum += rate[index];
        printf("No [%d]: %2f\n", index + 1, rate[index]);
        index++;
    }
    printf("Total avg: %2f\n", sum / index);
    printf("Range: A: %d B:% d C :%d D: %d\n", rank[0], rank[1], rank[2], rank[3]);
    for (int i = 0; i < 4; i++)
    {
        if (max <= rank[i])
            max = rank[i];
    }  
    printf("Max_range: ");

    for (int i = 0; i < 4; i++)
    {
        if (max == rank[i])
        {
            if (i == 0)
                printf("    A:%d", rank[i]);
            else if (i == 1)
                printf("    B:%d", rank[i]);
            else if (i == 2)
                printf("    C:%d", rank[i]);
            else if (i == 3)
                printf("    D:%d", rank[i]);
        }
    }
    printf("\n");
}