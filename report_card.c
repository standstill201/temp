#include <stdio.h>

int main()
{
    int kor_score;
    int eng_score;
    char name;

    printf("Eng:");
    scanf(" %d", &eng_score);


    printf("Kor:");
    scanf(" %d", &kor_score);


    printf("Name:");
    scanf(" %c", &name);

    printf("%s\n", "NAME\tENGLISH\tKOREAN\tTOTAL\tAVERAGE");
    printf("%s\n", "\tSCORE\tSCORE\tSCORE\tSCORE");

    printf("%c\t%d\t%d\t%d\t%.2f\n", name, eng_score, kor_score, eng_score+kor_score, (eng_score+kor_score) / 2.0);
    

    return (0);
}