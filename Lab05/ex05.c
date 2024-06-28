#include <stdio.h>
#include <string.h>
#include <math.h>

void factorial()
{
    int number;
    int factorial = 1;

    printf("\n------Factorial------\n");
    printf("Enter number: ");
    scanf("%d",&number);

    for(int i = 1; i <= number; i++)
    {
        factorial = factorial * i;
    }
    printf("Factorial of %d = %d\n",number,factorial);
}

void summation_number()
{
    int n;
    int sum;
    
    printf("\n------Summation Number------\n");
    printf("Enter n:");
    scanf("%d",&n);

    sum = (n*(n+1)/2);
    printf("Summation form 1 to %d: %d\n",n,sum);  
}

void square_root()
{
    float number;
    float result;

    printf("\n------Square Root------\n");
    printf("Enter number: ");
    scanf(" %f",&number);

    result = sqrt(number);

    printf("Square of %.2f = %.2f\n",number,result);

}

void prime_number()
{
    int number;
    printf("\n------Prime Number------\n");
    printf("Enter number: ");
    scanf("%d",&number);

    int i;
    for (i = 2; i <= number-1; i++){
        if (number%i==0)
            break;
        }

        if (number == i){
            printf("%d is prime number\n",number);
        } else {
            printf("%d is not prime number\n",number);
        }   
}

void display()
{
    printf("\nChoose number (from 1-5)\n");
    printf("1.Factorial\n");
    printf("2.Summation Number\n");
    printf("3.Square Root\n");
    printf("4.Prime Number\n");
    printf("5.exit\n");
}

void endDisplay()
{
    printf("\n---------------------------\n");
}
   
int main ()
{
    int show = 1;

    while(show){

        display();

        printf("\nEnter Choice:");
        scanf("%d",&show);
        
        switch (show)
        {
            case 1:
                factorial();
            break;

            case 2:
                summation_number();
            break;

            case 3:
                square_root();
            break;

            case 4:
                prime_number();
            break;
        
            default:
                endDisplay();
                return 1;
            break;
        }
    }

    return 0;
}