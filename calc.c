#include <stdio.h>
#include <math.h>

char op;
double num1;
double num2;

int main(void)
{
    

printf("Select an operator (+ - * /):");
scanf("%c", &op); 
printf("Enter first number: ");
scanf("%lf", &num1);
printf("Enter second number: ");
scanf("%lf", &num2);

    switch (op)
    {
    case '+':
        printf("The sum of %lf and %lf is %lf\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("The difference of %lf and %lf is %lf\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("The product of %lf and %lf is %lf\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Cannot divide by zero\n");
            break;
        }
        printf("The quotient of %lf and %lf is %lf\n", num1, num2, num1 / num2);
        break;
    
    default:
        printf("Invalid operator\n");
        break;
    }
    return 0;
}