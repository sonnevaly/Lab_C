#include <stdio.h>

struct students
{
    char surname[20];
    char name[25];
    int age;
};

int main(){

struct students students[10];

    for(int i = 0; i < 10; i++){
        printf("\nStudent%d Detials\n",i+1);
        printf("Enter surname: ");
        scanf("%s",students[i].surname);

        printf("Enter Name: ");
        scanf("%s",students[i].name);

        printf("Enter Age: ");
        scanf("%d",&students[i].age);
    }

    int youngestIndex = 0;

    for(int i = 1; i < 10; i++){
        if()
    }


    return 0;
}
