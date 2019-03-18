#include <stdio.h>

typedef enum {
    true = 1,
    false = 0
} bool;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    bool hasCycle = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle == false) {
        return NULL;
    }
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main(int argc, char *argv[]) {
    return 0;
}