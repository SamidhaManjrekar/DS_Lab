#include <stdio.h>

int main() 
{
    int num, i;
    int PRN[5] = {53, 54, 55, 56, 57};
    float CGPA[5] = {8.82, 8.34, 7.54, 7.99, 9.01};
    char NAME[5] = {'S', 'R', 'M', 'C', 'I'};

    printf("the prn and CGPA of the students are:\n");

    for (i = 0; i < 5; i++) 
    {
        printf("PRN: %d, CGPA: %f, NAME: %c\n", PRN[i], CGPA[i], NAME[i]);
    }

    printf("Enter the PRN to be found: ");
    scanf("%d", &num);

    for (i = 0; i < 5; i++) 
    {
        if (PRN[i] == num) 
        {
            printf("Number found at position %d\n", i + 1);
            break;
        }
    }

    if (i == 5) 
    {
        printf("Number not found\n");
    }

    return 0;
}
