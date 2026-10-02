#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node*);
void isPrime(int);
void append(struct node**, int);

int main() {
	struct node *head = NULL;

	append(&head,5);
	append(&head,6);
	append(&head,1);
	append(&head,1);
	append(&head,9);
	append(&head,30);
	append(&head,30);
	append(&head,45);
	append(&head,84);
	append(&head,84);

	printList(head);

	int counter = 0;
	struct node *ptr1, *ptr2;
	ptr1 = head;
	ptr2 = head->next;
	while (ptr2 != NULL) {
		if (ptr1->data==ptr2->data) {
			counter++;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	printf("ardisik eleman sayisi : %d\n", counter);

	isPrime(counter);

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
	int length = 0;
	while (node != NULL) {
		length++;
		printf("%d\n", node->data);
		node = node->next;
	}
}

void isPrime(int number) {
	int counter = 0;
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			counter++;
	if (number == 1)
		printf("asal degil");
	else if (counter == 0)
		printf("asal");
	else
		printf("asal degil");
}