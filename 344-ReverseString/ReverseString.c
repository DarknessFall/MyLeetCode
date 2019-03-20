#include <stdio.h>

void reverseString(char* s, int sSize) {
    if (sSize == 1) {
        return;
    }
    
    int i = 0;
    for (int j = sSize - 1; j > i; j--) {
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        i++;
    }
}

int main(int argc, char *argv[]) {
    char s[] = "hello";
    reverseString(s, 5);
    printf("%s\n", s);

	return 0;
}