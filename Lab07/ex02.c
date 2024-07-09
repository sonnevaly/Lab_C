#include <stdio.h>

struct seller{
    char houseNumber[20];
    char sellerName[20];
    char road[20];
    char city[20];
};

int main (){
    int number;
    printf("\nEnter the seller\nNumber: ");
    scanf("%d",&number);

    struct seller s[number];

    for(int i = 0; i < number; i++){

        printf("\nSeller%d:\n",i+1);
        printf("Enter Name: ");
        scanf("%s", s[i].sellerName);

        printf("\nPlease Enter Seller Address\n");
        printf("Enter House Number: ");
        scanf("%s", s[i].houseNumber);

        printf("Enter Road: ");
        scanf("%s", s[i].road);

        printf("Enter City: ");
        scanf("%s", s[i].city);
        
        printf("\n");
    }

    printf("\n====Seller list====\n");
    for(int i = 0; i < number; i++){
        printf("Seller%d:\n",i+1);
        printf("Name: %s\n",s[i].sellerName);
        printf("House Number: %s\n",s[i].houseNumber);
        printf("Road: %s\n", s[i].road);
        printf("City: %s\n\n",s[i].city);
        
    }
    printf("===================");

    return 0;
}