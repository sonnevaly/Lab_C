#include<stdio.h>

//Function for addition of two int pointer by pointer
void addition (int *a , int *b){
*a = *a + *b; //Addition and stored the result in a
}

int main(){
int a = 9; 
int b = 2;

int *p_a = NULL; 
p_a = &a; //Declare ponter p_a to point varible a

printf("Before swap: (a:%d, b:%d)\n",a, b);

*p_a = a + b; // 9 + 2 = 11
b = *p_a - b; // 11 - 2 = 9
a = *p_a - b; // 11 - 9 = 2

printf("After swap: (a:%d, b:%d)\n", *p_a, b);

int *p_b;
p_b = &b; //Pointer p_b point to varible b

printf("Before sum: (a:%d, b:%d)\n", *p_a, *p_b);

addition(&a, &b); //Call  addition function with address of a and b

printf("After sum: (a:%d, b:%d)\n", a, b);

return 0;

}