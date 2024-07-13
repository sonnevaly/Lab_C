#include <stdio.h>
#include <string.h>

void shift_left(char *str, int n) {
    int len = strlen(str);
    if (n >= len) {
        str[0] = '\0'; 
        return;
    }

    char *src = str + n;
    char *dst = str;

    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }

    *dst = '\0'; 
}

int main() {
    char str[100];
    int n;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    printf("Enter the number of characters to shift left: ");
    scanf("%d", &n);

    shift_left(str, n);

    printf("String after left shift: %s\n", str);

    return 0;
}
