#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node *q) {
	int length = 0;
	while (q != NULL) {
		length++;
		printf("%d\n", q->data);
		q = q->next;
	}
	printf("eleman sayisi = %d\n", length);
	length = 0;
}

void cevrimseleDonustur(struct node *head) {
	struct node *ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = head;
}

void printCevrimsel(struct node *head) {
	struct node *ptr = head;
	do {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	} while (ptr != head);
}

struct node* bosaEkle(struct node *q, int x) {
	if (q != NULL)
		return q;
	q = (struct node*)malloc(sizeof(struct node));
	q->data = x;
	q->next = q;
	printf("tek eleman = %d\n", q->data);
	return q;
}

void ekle(struct node *head, int x) {
	struct node *yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	if (head == NULL) {
		bosaEkle(yeni, 5);
		return;
	}
	while (head->next == head)
		head = head->next;
	yeni->next = head->next;
	head->next = yeni;
}

int main() {
	struct node *dugum1, *dugum2, *dugum3;
	dugum1 = (struct node*)malloc(sizeof(struct node));
	dugum2 = (struct node*)malloc(sizeof(struct node));
	dugum3 = (struct node*)malloc(sizeof(struct node));
	dugum1->data = 15;
	dugum2->data = 20;
	dugum3->data = 25;
	dugum1->next = dugum2;
	dugum2->next = dugum3;
	dugum3->next = NULL;
	printList(dugum1);

	cevrimseleDonustur(dugum1);
	printCevrimsel(dugum1);

	struct node *yeni = NULL;
	// atama yapmazsak yeni isimli pointer NULL oldugu icin hata verir
	yeni = bosaEkle(yeni, 180);

	ekle(dugum3, 17);
	printCevrimsel(dugum1);

	getch();
	return 0;
}