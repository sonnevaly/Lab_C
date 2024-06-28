#include <stdio.h>

void numbers(int num1, int num2)
{
    if( num1 > num2){
        printf("%d is the greatest\n",num1);
    } else {
        printf("%d is the greatest\n",num2);
    }
}
int main(){
    
    int num1;
    int num2;

    printf("Enter number1: ");
    scanf("%d",&num1);

    printf("Enter number2: ");
    scanf("%d",&num2);

    numbers(num1, num2);
    // numbers; testing

return 0;
}