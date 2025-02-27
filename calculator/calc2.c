#include <stdio.h>
#include <math.h>

// Kalkulator ringkas hanya untuk aku belajar

char mat;
double num1;
double num2;

int main(void)
{
    printf("Pilihlah operator kau (+,-,*,/):");
    scanf("%c",&mat);

    printf("Letak nombor pertama: ");
    scanf("%lf",&num1);

    printf("Letaklah nombor kedua: ");
    scanf("%lf",&num2);

    switch(mat)
    {
        case '+':
            printf("Kalau tambah %lf dan %lf dapatlah %lf\n",num1,num2,num1+num2);
            break;
        
        case '-':
            printf("Kalau tolak pulak %lf dan %lf dapatlah %lf\n",num1,num2, num1-num2);
            break;

        case '*':
            printf("Kalau darab antara %lf dan %lf dapatlah %lf\n", num1, num2, num1*num2);
            break;
        
        case '/':
            if (num2==0)
            {
                printf("Mana boleh bahagi kosong \n");
            }
                
            printf("Kalau bahagia antara %lf dan %lf maka dapatlah %lf\n", num1, num2 , num1/num2);
            break;
        
        default:
            printf("Salah matematik kau ni\n");
            break;
        
        
        return 0;


    }
        










}