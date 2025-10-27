#include <stdio.h>
#include <stdlib.h>

float digit;
float result =0;

char equationIndex;

char operatorPick;
char operation;

void addition()
{
    printf("Please Type your number :"); 
    scanf("%f", &digit); 

    result = result+digit;
}

void substraction()
{
    printf("Please Type your number :"); 
    scanf("%f", &digit); 

    result -= digit;
}

void multiplification()
{
    printf("Please Type your number :"); 
    scanf("%f", &digit); 

    result = result*digit;
}

void division()
{
    printf("Please Type your number :"); 
    scanf("%f", &digit); 

    if(digit == 0)
    {
        printf("Error Cannot Divide by 0 \n");
    }else result = result/digit;
}

void solveEquation()
{
    printf("=============================================================================================== \n");
    printf("1. Ax + b = 0 \n");
    printf("2. Ax^2 + bx + c = 0 \n");
    printf("3. Normal Calculator \n");

    while(1)
    {
        printf("Please select a number");
        scanf(" %c", &equationIndex);

        if(equationIndex == '1')
        {
            //First Equation
        }
        else if(equationIndex == '2')
        {
            //Second Equation
        }
        else if(equationIndex == '3')
        {
            break;
        }
        else
        {
            printf("Please select either 1, 2, 3 \n");
            continue;
        }
    }
}

int main()
{
    printf("=============================================================================================== \n");
    printf("                                        CASIO          CALCULATOR                     \n");
    printf("=============================================================================================== \n");
    printf("IF YOU WANT TO QUIT TYPE 'q' AND IF YOU WANT TO RESET MEMORY TYPE 'r' \n");
        printf("IF YOU WANT TO SOLVE EQUATIONS PLEASE TYPE 'e'\n");
    printf("=============================================================================================== \n");

    while(1)
    {
        printf("Memory is : %f \n", result);

        printf("Please type your operation :");
        scanf("%s", &operatorPick);

        if(operatorPick == 'q')
        {
            break;
        }else if (operatorPick == 'r')
        {
            result = 0;
            printf("Memory Reset ! \n");
            continue;
        }else if (operatorPick == 'e')
        {
            solveEquation(); 
            continue;
        }

        if(operatorPick == '+' || operatorPick == '-' || operatorPick == '*' ||operatorPick == '/')
        {
            switch(operatorPick)
            {
                case '+': addition(); continue;
                case '-': substraction(); continue;
                case '*': multiplification(); continue;
                case '/': division(); continue;
            }
        }else printf("Error please Pick a symbol + - * / !! \n"); continue;
    }

  

    return 0;
}