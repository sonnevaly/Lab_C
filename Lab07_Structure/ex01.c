#include <stdio.h>
#include <string.h>

struct products
{
    int id;
    char produceDate[20];
    char expireDate[20];
    char name[50];
    char color[20];
} ;

int main(){

    int number;
    printf("Number Product for Input: ");
    scanf("%d",&number);

    struct products p[number];

    for(int i = 0; i < number; i++){

        printf("\nEnter details for Products%d\n",i+1);

        printf("Enter ID: ");
        scanf("%d", &p[i].id);

        printf("Enter Name: ");
        scanf("%s", p[i].name);

        printf("Enter Produce Date(DD-MM-YY): ");
        scanf("%s", p[i].produceDate);

        printf("Enter Expire Date(DD-MM-YY): ");
        scanf("%s", p[i].expireDate);

        printf("Enter Color: ");
        scanf("%s", p[i].color);

        printf("\n");
    }


    for(int i = 0; i < number; i++){
        printf("Product%d:\n",i+1);

        printf("ID: %d\n", p[i].id);
        printf("Name: %s\n", p[i].name);
        printf("Produce Date: %s\n", p[i].produceDate);
        printf("Expire Date: %s\n", p[i].expireDate);
        printf("Color: %s\n\n", p[i].color);
    }

    return 0;
}