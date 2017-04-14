/**
 *
 * Insert a new node into a list and keep the list sorted
 * The key of each node is string type
 * Sorted means the keys are sorted in alphabetic order
 *
 * I meet this question when I interviewed at qualcomm atheros inc 
 * in 3/1/2017 at the first round with Sol Kavy
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

struct Node {
	struct Node *next;
	char str[MAX_LEN];
};

void insert(struct Node* *head_ref, struct Node *z)
{
	if (z == NULL) {
		return;
	}

	if (*head_ref == NULL) {
		*head_ref = z;
		return;
	}

	struct Node *p = *head_ref;
	
	// if z is less than the first node
	if (strcmp(z->str, p->str) <= 0) {
		z->next = p;
		*head_ref = z;
		return;
	}

	// iterate the list to find the first node that z is less than
	while (p->next) {
		if (strcmp(z->str, p->next->str) <= 0) {
			break;
		}
		p = p->next;
	}

	if (p->next) {	// p->next is less than z
		z->next = p->next;
	}
	
	p->next = z;
	return;
}

void print_list(struct Node *head)
{
	while (head) {
		printf("%s ", head->str);
		head = head->next;
	}
	printf("\n");
}

int main(void)
{
	struct Node nodes[5];

	int i;
	for (i = 0; i < 5; i ++) {
		nodes[i].next = NULL;
	}

	strcpy(nodes[0].str, "raven");
	strcpy(nodes[1].str, "cat");
	strcpy(nodes[2].str, "can");
	strcpy(nodes[3].str, "mouse");
	strcpy(nodes[4].str, "zebra");

	struct Node *head = NULL;

	for (i = 0; i < 5; i ++) {
		insert(&head, &nodes[i]);
		print_list(head);
	}
	return 0;
}
