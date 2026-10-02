#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printItem(struct Node *iter, int index){
    for (int i = 0; i < index; i++)
    {
        iter = iter->next;
    }
    
    printf("%d\n", iter->data);
}

void removeItem(struct Node *iter, int index){
    for (int i = 0; i < index - 1; i++)
    {
        iter = iter->next;
    }

    struct Node *temp = iter->next;
    iter->next = iter->next->next;

    free(temp);
}

void removeHead(struct Node **head){
     struct Node *temp = *head;
     *head = temp->next;
     free(temp);
}

void append(struct Node *iter, int num)
{
    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    newItem->data = num;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = newItem;
    newItem->next = NULL;
}

void push(struct Node **head, int num)
{
    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    newItem->data = num;

    newItem->next = *head;
    *head = newItem;
}

void insert(struct Node *iter, int index, int num){
    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    newItem->data = num;

    for (int i = 0; i < index; i++)
    {
        iter = iter->next;
    }

    newItem->next = iter->next;
    iter->next = newItem;
}

int main()
{
    struct Node *list = (struct Node *)malloc(sizeof(struct Node));
    list->data = 5;
    list->next = NULL;

    append(list, 3);
    append(list, 28);
    append(list, 32);
    append(list, 17);
    append(list, 9);

    push(&list, 65);

    insert(list, 2, 25);

    printList(list);

    printItem(list, 4);

    removeItem(list, 3);

    removeHead(&list);

    printList(list);
}