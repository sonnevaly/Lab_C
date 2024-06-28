#include <stdio.h>
#include <stdlib.h>

int main() {
    char fileName[100];
    FILE *file;
    char ch;

    printf("Input a file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return 0;
}
