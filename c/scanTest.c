#include <stdio.h>

int main(){
    char* s;
    fgets(s, 10, stdin);
    printf("%c", s[0]);
}