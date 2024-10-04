#include <stdio.h>

int main()
{
    int frac1_numerator;
    int frac1_denominator;
    int frac2_numerator;
    int frac2_denominator;
    int common_denominator;
    int result_numerator;
    int divider = 2;

    scanf("%d/%d %d/%d", &frac1_numerator, &frac1_denominator, &frac2_numerator, &frac2_denominator);
    common_denominator = frac1_denominator * frac2_denominator;

    result_numerator = frac1_numerator * frac2_denominator + frac2_numerator * frac1_denominator;


    while (divider < result_numerator)
    {
        if (common_denominator % divider == 0 && result_numerator % divider == 0)
        {
            common_denominator /= divider;
            result_numerator /= divider;
        }
        divider++;
    }

    printf("Sum: %d / %d\n", result_numerator, common_denominator);
    printf("Avg: %.2f \n", result_numerator / (float)common_denominator / 2.0);
    


    return(0);
}