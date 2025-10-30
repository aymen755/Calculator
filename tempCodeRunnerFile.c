#include <stdio.h>
#include <stdlib.h>

int i = 0;

float sum;

float digits[9];
char digitIndex =0;

char inputs[50];
char numbers[30];
char numberIndex;

void Addition()
{
    printf("You are performing addition \n");

    if(digitIndex == 0)
    {
        digits[digitIndex] = atof(numbers);
        printf("%f \n", digits[digitIndex]);
        digitIndex++;
    }else if(digitIndex == 1)
    {
        printf("The digit index is 1 \n");
        digits[digitIndex] = atof(numbers);
        printf("%f \n", digits[digitIndex]);
        sum = digits[0] + digits[1];
        digitIndex = 0;

        digits[0] = '\0';
        digits[1] = '\0';
    }
}

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

            printf("You have %s \n", numbers);
        }else if(m == '+' || m == '-')
        {
            numbers[numberIndex] = '\0';
            numberIndex = 0;

            switch(m)
            {
                case '+' : Addition(); continue;
            }
        }
    }  
    
    printf("The result is : %f", sum);
}