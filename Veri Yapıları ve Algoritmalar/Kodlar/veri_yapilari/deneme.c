#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node*);
void append(struct node**, int);

int main() {
	struct node *head=NULL;
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
	printList(head);

	getch();
	return 0;
}

void append(struct node** head, int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
    struct node* last = (*head);
	node->data=data;
	node->next=NULL;
    if ((*head)==NULL){
        (*head)=node;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=node;
    return;
}

void printList(struct node *node) {
	while (node != NULL) {
		printf("%d\n", node->data);
		node = node->next;
	}
}