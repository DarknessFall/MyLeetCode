#include <stdio.h>

struct Node {
	int value;
	struct Node *next;
};

struct Node * reverseLinkedList(struct Node *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct Node *pre = head;
	struct Node *current = pre->next;
	struct Node *next;

	do {
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	} while (current != NULL);

	head->next = NULL;
		
	return pre;
}

void printfLinkedList(struct Node *head) {
	if (head == NULL) {
		printf("Empty!");

		return;
	}

	struct Node *current = head;
	do {
		printf("%d", current->value);
		current = current->next;
	} while (current != NULL);
}

int main(int argc, char *argv[]) {
	struct Node e = {5, NULL};
	struct Node d = {4, &e};
	struct Node c = {3, &d};
	struct Node b = {2, &c};
	struct Node a = {1, &b};

	struct Node *newHead = reverseLinkedList(&a);
	printfLinkedList(newHead);
	
	return 0;
}