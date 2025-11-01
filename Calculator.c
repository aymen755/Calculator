#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

int i = 0;
int IsSqrt;

double sum = 0;
double prio = 0;
double memory =0;
double digit = 0;
double x, y;

char menuIndex;
int colorIndex;

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
                   x2=(-b-sqrt(d))/(2*a);
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

void SquareRoot()
{
    if (prioOperator == 'f')
    {
        prio = sqrt(digit);
    }
    if(IsSqrt)
    {
        digit = sqrt(digit);
        IsSqrt = 0;
    }
}

void assignVariable(char s, double X)
{
    printf("Please Type away your variable %c :" , s);
    scanf("%lf", &X);

    numberIndex = snprintf(numbers, sizeof(numbers), "%g", X);
}


int main()
{
    setColor(5);
    printf("===============================================================================================\n");
    printf("                                    CASIO CALCULATOR                                           \n");
    printf("===============================================================================================\n");
    printf("1. GUIDE\n");
    printf("2. CALCULATION\n");
    printf("3. EQUATIONS\n");
    printf("4. RESET\n");
    printf("5. COLORS\n");
    printf("6. QUIT\n");
    printf("7. CREDITS\n");
    printf("===============================================================================================\n");

    while (1)
    {
        LoadingScreen();

        if(menuIndex == '7')
        {
            printf("SERINE MADJOUDJ \n");
                for (i = 0; i < 30; i++)
                {
                Sleep(15); 
                }
            printf("\n");

            printf("GUERNICHE AYMEN ABDERRAHIM \n");
                for (i = 0; i < 30; i++)
                {
                Sleep(15); 
                }
            printf("\n");

            printf("MARYAM BOUDJEMIA \n");
                for (i = 0; i < 30; i++)
                {
                Sleep(15);  
                }
            printf("\n");

            printf("BOUCHIKHI ABDERRAHIM \n");
                for (i = 0; i < 30; i++)
                {
                Sleep(15); 
                }
            printf("\n");

            printf("Algorithm Teachers : KHENNAK ILYES, HOUASSINE, HASSILYNDA \n");
            for (i = 0; i < 30; i++)
                {
                Sleep(15); 
                }
            printf("\n");

            printf("ARCHI TEACHERS : DJIDEL \n");
            printf("\n");

            printf("THANK YOU, THIS PROJECT WAS MADE BY THE ING OF INFORMATIQUE IN BAB EZZOUAR THANKS TO THE HELP OF OUR BELOVED TEACHERS");
        }
        else if (menuIndex == '6')
        {
            printf("Goodbye!\n");
            break;
        }else if(menuIndex == '5')
        {
            printf("|1 = BLUE\n|2 = GREEN \n|4 = RED\n|5 = PURPLE \n|6 = YELLOW \n");

            printf("Please Select a color : \n");
            scanf("%d", &colorIndex);
            if(colorIndex >= 0 && colorIndex <= 15)
            {
            setColor(colorIndex);
            continue;
            }else
            {
                printf("ERROR WE WILL DELETE ALL YOUR DATA SAY GOODBYE TO YOUR PC");
                break;
            }

        }
        else if (menuIndex == '4')
        {
            sum = prio = digit = memory = 0;
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
            printf("Guide: \n");

            printf("This is a pseudo-Casio Calculator, it can parse strings of letters to make a full calculation that can work in human language (5+4*3/2), some signs you need to know are : \n");
            printf("|+ = Addition\n|- = Subtraction \n|* = multiplication\n|/ = division \n|f = Square Root of a number after it so f4 = 2 \n");
            printf("There are other functionalities such as assinging X or Y as variables in your calculation \n");

            continue;
        }
        else
        {
            printf("Please select a valid option .\n");
            continue;
        }

        while (1)
        {
            printf("\nPlease enter a random expression (If you have to quit press 'q') : ");
            scanf("%s", inputs);

            sum = 0;
            prio = 0;
            sumOperator = '+';
            prioOperator = ' ';
            numberIndex = 0;

            for (i = 0; inputs[i] != '\0'; i++)
            {
                char m = inputs[i];

                if(m == 'q') 
                {
                    printf("You want to quit?");
                    return 0;
                }else if((m == 'X' || m == 'Y'))
                {
                    if(m == 'X')
                    {
                        assignVariable(x, m);
                    }
                     
                    if(m == 'Y')
                    {
                        assignVariable(y, m);
                    }

                }else if (m >= '0' && m <= '9' || m == '.')
                {
                    numbers[numberIndex++] = m;
                }else if(m == 'm')
                {
                    numberIndex = snprintf(numbers, sizeof(numbers), "%g", memory);
                }
                else if (m == '+' || m == '-' || m == '*' || m == '/' || m == 'f')
                {
                    numbers[numberIndex] = '\0';
                    digit = atof(numbers);
                    numberIndex = 0;

                    if (m == '*' || m == '/' || m == 'f') 
                    {
                        SquareRoot();
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

            SquareRoot();
            Priority();

            if (sumOperator == '+')
                sum += prio;
            else
                sum -= prio;

            printf("The result is: %lf\n", sum);
            memory = sum;

            sumOperator = '+';
            prioOperator = ' ';

            memset(inputs, 0, sizeof(inputs));
            memset(numbers, 0, sizeof(numbers));
        }

        continue;
    }
    return 0;
}