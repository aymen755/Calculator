#include <stdio.h>
#include <stdlib.h>

int i = 0;

float sum;
float digit1;

char inputs[50];
char operationIndex;
char numbers[30];
char numberIndex;

int main()
{
    printf("Please enter a random number :");
    scanf("%s", &inputs);

    for(i; inputs[i] != '\0'; i++)
    {
        char m = inputs[i];

        if(m >= '0' && m <= '9')
        {
            numbers[numberIndex++] = m;
        }else if(m == '+' || m == '-')
        {
            numbers[numberIndex] = '\0';
            numberIndex = 0;

            digit1 = atof(numbers);
        }
    }     
    numbers[numberIndex] = '\0';
    numberIndex = 0;

    float digit2 = atof(numbers);

    sum = digit1+digit2;

    printf("The result is : %f", sum);
}