#include <stdio.h>
#include <string.h>

void filter(char *str, char c) {
    char *src = str, *dst = str;
    while (*src != '\0') {
        if (*src != c) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

int main() {
    char str[100];
    char c;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    printf("Enter the character to filter out: ");
    scanf(" %c", &c);

    filter(str, c);

    printf("Filtered string: %s\n", str);

    return 0;
}
