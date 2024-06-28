#include <stdio.h>
#include<string.h>

void checkChar_inString(char character, char string[])
{
    for(int i = 0; i < strlen(string); i++){
        if(character == string[i]){
            printf("'%c' found in string\n",character);
            return;            
        }
    }
    printf("Not found '%c' in string\n",character);            
}

int main(){

    char character;
    char string[100];
    
    printf("Enter string: ");
    scanf("%s",string);
    
    printf("Find character: ");
    scanf(" %c",&character);
    
    checkChar_inString(character, string);

return 0;
}