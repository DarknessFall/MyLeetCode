#include <stdio.h>

typedef enum {
    true = 1,
    false = 0
} bool;

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isAnagram(char* s, char* t) {
    int result[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        result[s[i] - 'a']++;
    }
    for (int i = 0; t[i] != '\0'; i++) {
        result[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (result[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char *argv[]) {
    return 0;
}