#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    struct ListNode *nextNext = node->next->next;
    node->next = nextNext;
}

int main(int argc, char *argv[]) {
    return 0;
}