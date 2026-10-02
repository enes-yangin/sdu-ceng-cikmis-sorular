#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void basaEkle(struct node **, int);
void arayaEkle(struct node *, int, int);
void bastanSil(struct node **);
void printList(struct node *);
void cevir(struct node *, struct node *);
void ekle(struct node *, int);

int main(){
    struct node *dugum1, *dugum2, *dugum3;
    dugum1 = (struct node *)malloc(sizeof(struct node));
    dugum2 = (struct node *)malloc(sizeof(struct node));
    dugum3 = (struct node *)malloc(sizeof(struct node));
    dugum1->data = 4;
    dugum2->data = 1;
    dugum3->data = 5;
    dugum1->prev = NULL;
    dugum1->next = dugum2;
    dugum2->prev = dugum1;
    dugum2->next = dugum3;
    dugum3->prev = dugum2;
    dugum3->next = NULL;

    printList(dugum1);
    basaEkle(&dugum1, 9);
    arayaEkle(dugum2, 8, 1);
    printList(dugum1);
    bastanSil(&dugum1);
    printList(dugum1);

    ekle(dugum1,14);
    printf("cevirme islemi\n"); 
    struct node *dugum4 = (struct node *)malloc(sizeof(struct node));
    dugum4->data = 14;
    dugum4->next = NULL;

    //????????????
    cevir(dugum1, dugum4);
    printList(dugum4);

    getch();
    return 0;
}

void basaEkle(struct node **head, int x){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->prev = NULL;
    ptr->next = (*head);
    (*head)->prev = ptr;
    (*head) = ptr;
}

void arayaEkle(struct node *head, int x, int y){
    struct node *yeni = (struct node *)malloc(sizeof(struct node));
    yeni->data = x;
    yeni->prev = NULL;
    struct node *ptr = head;
    while (ptr != NULL){
        if (ptr->data == y)
            break;
        ptr = ptr->next;
    }
    if (ptr == NULL)
        return;
    yeni->next = ptr->next;
    yeni->prev = ptr;
    ptr->next->prev = yeni;
    ptr->next = yeni;
}

void bastanSil(struct node **head){
    struct node *ptr = (*head);
    (*head) = ptr->next;
    ptr->next->prev = NULL;
    free(ptr);
}

void printList(struct node *q){
    int length = 0;
    while (q != NULL){
        length++;
        printf("%d\n", q->data);
        q = q->next;
    }
    printf("eleman sayisi = %d\n", length);
    length = 0;
}

void ekle(struct node *head, int x){
    struct node *yeni = (struct node *)malloc(sizeof(struct node));
    yeni->data = x;
    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = yeni;
    yeni->next = NULL;
}

void cevir(struct node *head, struct node *tekBas){
    struct node *ptr = head;
    while (ptr != NULL){
        ekle(tekBas, ptr->data);
        ptr = ptr->next;
    }
}
