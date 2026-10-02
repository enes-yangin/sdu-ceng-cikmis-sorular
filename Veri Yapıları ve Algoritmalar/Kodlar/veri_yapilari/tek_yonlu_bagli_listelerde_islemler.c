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

// sanirim ekleme - anlamadım
void insert(struct node* prev_node, int x) {
	if (prev_node == NULL)
		return;
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	yeni->next = prev_node->next;
	prev_node->next = yeni;
}

// bastan silme
void bastanSilme(struct node** head_ref) {
	(*head_ref) = (*head_ref)->next;
	free(*head_ref);
}

// silme
void silme(struct node* ptr, int x) {
	struct node* prev_node;
	while (ptr->next->data != x) {
		ptr = ptr->next;
	}
	prev_node = ptr;
	struct node* silinen = prev_node->next;
	prev_node->next = ptr->next->next;
	free(silinen);
}

// basa ekle
void push(struct node** head_ref, int x) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	yeni->next = (*head_ref);
	(*head_ref) = yeni;
}

// araya ekle
void arayaEkle(struct node* ptr, int x) {
	// dugum olusturma
	struct node* yeni;
	yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;

	while (ptr->data != 20) {
		ptr = ptr->next;
	}

	yeni->next = ptr->next;
	ptr->next = yeni;
}

void tersCevir(struct node** x) {
	struct node *q, *r, *s;
	q = (struct node*)malloc(sizeof(struct node));
	r = (struct node*)malloc(sizeof(struct node));
	s = (struct node*)malloc(sizeof(struct node));
	q = *x;
	r = NULL;
	while (q != NULL) {
		s = r;
		r = q;
		q = q->next;
		r->next = s;
		
	}
	*x = r;
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

	insert(dugum3,30);
	printList(dugum1);

	push(&dugum1, 10);
	printList(dugum1);

	arayaEkle(dugum1, 22);
	printList(dugum1);

	silme(dugum1, 20);
	printList(dugum1);

	tersCevir(&dugum1);
	printList(dugum1);

	getch();
	return 0;
}