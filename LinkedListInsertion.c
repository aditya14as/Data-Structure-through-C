#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case-1: Insert an element at the strat of the linked list

struct Node *InsertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = element;
    return ptr;
}

// Case-2: Insert an element between linked list
struct Node *InsertInBetween(struct Node *head, int element, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = element;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case-3: Insert at the End
struct Node *InsertAtEnd(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case-4: Insert at the Node
struct Node *InsertAtNode(struct Node *head, struct Node *prevNode, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 9;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = NULL;

    printf("\nLinked List before Insertion\n");
    LinkedListTraversal(head);

    // head=InsertAtFirst(head,7);
    // head = InsertInBetween(head, 14, 3);
    // head=InsertAtEnd(head,100);

    head = InsertAtNode(head, second, 45);

    printf("\nLinked List after Insertion\n");

    LinkedListTraversal(head);
}