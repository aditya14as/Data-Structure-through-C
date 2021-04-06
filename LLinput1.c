#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *head)
{
    struct Node *dummy = head;
    while (dummy != NULL)
    {
        printf("%d ", dummy->data);
        dummy = dummy->next;
    }
    printf("\n");
}

struct Node *AddAtEmpty(struct Node *head, int element)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;
    head = temp;
    return head;
}

struct Node *AddAtEnd(struct Node *head, int element)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;

    struct Node *dummy = head;

    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }
    dummy->next = temp;
    return head;
}

struct Node *CheckOrAdd(struct Node *head, int element, int n)
{

    int i = 1;
    struct Node *dummy;
    dummy = head;
    while (dummy->data != element && i != n)
    {
        dummy = dummy->next;
        i++;
    }
    if (i == n)
    {
        head = AddAtEnd(head, element);
    }
    else
    {
        printf("\nElement found at index %d\n", i);
    }
    return head;
}

int main()
{
    int n, i, data, element;
    struct Node *head = NULL;
    printf("Enter no of nodes: ");
    scanf("%d", &n);

    printf("Enter 1 element: ");
    scanf("%d", &data);
    head = AddAtEmpty(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter %d element: ", i);
        scanf("%d", &data);
        fflush(stdin);
        head = AddAtEnd(head, data);
    }
    printf("\nAll lists are:\n");
    Traverse(head);

    printf("\nEnter an element to check whether it's present in list or not: ");
    scanf("%d", &element);
    head = CheckOrAdd(head, element, n);

    printf("\nAll lists are:\n");
    Traverse(head);

    return 0;
}