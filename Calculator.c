#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

int i = 0;

double sum = 0;
double prio = 0;
double memory =0;
double digit = 0;

char menuIndex;

char inputs[50];
char sumOperator = '+';
char prioOperator = ' ';

char numbers[30];
int numberIndex = 0;

double a,b,c, d, x1, x2;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void LoadingScreen()
{
    printf("\nPlease select a number: ");
    scanf(" %c", &menuIndex); 

    printf("\n\nLoading...\n");

    for (i = 0; i < 30; i++)
    {
            printf("%c", 254);
            Sleep(20); 
    }
    printf("\n");
}

void Priority()
{
    if (prioOperator == '*')
    {
        prio *= digit;
    }
    else if (prioOperator == '/')
    {
        if (digit == 0)
        {
            printf("Error: Division by zero!\n");
            return;
        }
        prio /= digit;
    }
    else
    {
        prio = digit;
    }
}

void SolveEquation()
{
    printf("Please Type away your a, b, and c in order : ");
    
    scanf("%lf %lf %lf",&a,&b,&c);

    LoadingScreen();

       if (a==0) {
           if (b==0) {
                if (c==0){
                   printf("There is infinite solutions \n");
            }else{
                  printf("there no solution \n");
            }
        }else{
              printf("x= %lf",-c/b);
        }
        }else{
          d=b*b-4*a*c;
              if (d>0) {
                   x1=(-b+sqrt(d))/(2*a);
                   x2=(-b-sqrt(d))    /(2*a);
                printf("You got Two Solutions x1= %.2lf et x2= %.2lf \n",x1,x2);

            }else {
                if (d==0) {

                    x1=-b/2*a;
                    printf("%lf",x1);

                } else {
                     printf("no solutions in R \n");
            }
        }
    }
}


int main()
{
    while (1)
    {
    setColor(5);
    printf("===============================================================================================\n");
    printf("                                    CASIO CALCULATOR                                           \n");
    printf("===============================================================================================\n");
    printf("1. GUIDE\n");
    printf("2. CALCULATION\n");
    printf("3. EQUATIONS\n");
    printf("4. RESET\n");
    printf("5. QUIT\n");
    printf("6. CREDITS\n");
    printf("===============================================================================================\n");

        LoadingScreen();

        if (menuIndex == '5')
        {
            printf("Goodbye!\n");
            break;
        }
        else if (menuIndex == '4')
        {
            sum = prio = digit = 0;
            sumOperator = '+';
            prioOperator = ' ';
            printf("Memory Reset!\n");
            continue;
        }
        else if (menuIndex == '3')
        {
           SolveEquation();
            continue;
        }
        else if (menuIndex == '2')
        {
            printf("calculation start!!\n");
        }
        else if (menuIndex == '1')
        {
            printf("Guide:\n");
            continue;
        }
        else
        {
            printf("Please select a valid option .\n");
            continue;
        }

        while (1)
        {
            printf("\nPlease enter a random expression : ");
            scanf("%s", inputs);

            sum = 0;
            prio = 0;
            sumOperator = '+';
            prioOperator = ' ';
            numberIndex = 0;

            for (i = 0; inputs[i] != '\0'; i++)
            {
                char m = inputs[i];

                if (m >= '0' && m <= '9' || m == '.')
                {
                    numbers[numberIndex++] = m;
                }else if(m == 'm')
                {
                    snprintf(numbers, sizeof(numbers), "%g", memory);
                }
                else if (m == '+' || m == '-' || m == '*' || m == '/')
                {
                    numbers[numberIndex] = '\0';
                    digit = atof(numbers);
                    numberIndex = 0;

                    if (m == '*' || m == '/') 
                    {
                        Priority();
                        prioOperator = m;
                    }
                    else if (m == '+' || m == '-')
                    {
                        Priority();

                        if (sumOperator == '+' )
                            sum += prio;
                        else
                            sum -= prio;

                        sumOperator = m;
                        prioOperator = ' ';
                    }
                }else
                {
                    printf("ERROR CHARACTER NOT IDENTIFIED PLEASE TRY AGAIN \n");
                    continue;
                }
            }

            numbers[numberIndex] = '\0';
            digit = atof(numbers);
            Priority();

            if (sumOperator == '+')
                sum += prio;
            else
                sum -= prio;

            printf("The result is: %lf\n", sum);
            memory = sum;
            printf("The Memory is : %lf", memory);

            sumOperator = '+';
            prioOperator = ' ';

            memset(inputs, 0, sizeof(inputs));
            memset(numbers, 0, sizeof(numbers));
        }
    }
    return 0;
}