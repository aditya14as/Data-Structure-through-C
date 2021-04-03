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

// Case 1: Deletion at start
struct Node *DeletionAtStart(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deletion in Between
struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }

    ptr->next = q->next;
    free(q);
    return head;
}
// Case 3: Deletion at last
struct Node *DeletionAtLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;

    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }

    ptr->next = NULL;
    free(q);
    return head;
}

// Case 4: Delete a particular Number
struct Node *DeleteNo(struct Node *head, int element)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;

    while (q->data != element && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == element)
    {
        ptr->next = q->next;
        free(q);
    }
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

    printf("\nLinked List before deletion\n");
    LinkedListTraversal(head);

    printf("\nLinked List after deletion\n");

    //head=DeletionAtStart(head);
    //head= DeleteAtIndex(head,2);
    //head=DeletionAtLast(head);
    head = DeleteNo(head, 10);
    LinkedListTraversal(head);
}