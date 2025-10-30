#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

float sum = 0;
float prio = 0;
float digit = 0;

char inputs[50];
char sumOperator = '+';
char prioOperator = ' ';

char numbers[30];
char numberIndex = 0;

void Priority()
{
    if(prioOperator == '*')
    {
        prio *= digit;
    }
    else if(prioOperator == '/')
    {
        if (digit ==0){
            printf("Error\n");
        }
        prio /= digit;
    }
    else
    {
        prio = digit;
    }
}

int main()
{
    for(;;)
    {
        printf("Please enter a random number :");
        scanf("%s", inputs);

        for(i = 0; inputs[i] != '\0'; i++)
        {
            char m = inputs[i];

            if(m >= '0' && m <= '9')
            {
                numbers[numberIndex++] = m;
            }
            else
            {
                numbers[numberIndex] = '\0';
                digit = atof(numbers);
                numberIndex = 0;

                if(m == '*' || m == '/')
                {
                    Priority();
                    prioOperator = m;
                }
                else if(m == '+' || m == '-')
                {
                    Priority();

                    if(sumOperator == '+')
                        sum += prio;
                    else
                        sum -= prio;

                    sumOperator = m;
                    prioOperator = ' ';
                }
            }
        }

        numbers[numberIndex] = '\0';
        digit = atof(numbers);

        Priority();

        if(sumOperator == '+')
        {
            sum += prio;
        }else sum -= prio;

        printf("The result is : %f \n", sum);

        sum=0;
        prio=0;
        
        sumOperator = '+';
        prioOperator = ' ';

        memset(inputs, 0, sizeof(inputs));
        memset(numbers, 0, sizeof(numbers));
        numberIndex = 0;
        continue;
    }
}