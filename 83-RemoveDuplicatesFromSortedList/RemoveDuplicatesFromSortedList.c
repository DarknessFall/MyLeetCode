#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    
    struct ListNode *current = head;
    while (current->next != NULL) {
        struct ListNode *next = current->next;
        if (next->val == current->val) {
            current->next = next->next;
        } else {
            current = current->next;
        }
    }
    
    return head;
}

int main(int argc, char *argv[]) {
    return 0;
}