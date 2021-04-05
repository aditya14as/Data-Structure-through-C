#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *head)
{
    struct Node *tra;
    tra = head;
    if (tra == NULL)
    {
        printf("List is Empty");
        return;
    }

    while (tra != NULL)
    {
        printf("%d\n", tra->data);
        tra = tra->next;
    }
}

struct Node *AddAtEmpty(struct Node *head, int element)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = head;
    head = temp;
    return head;
}

struct Node *AddAtEnd(struct Node *head, int element)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    struct Node *dummy = head;

    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }
    dummy->next = temp;
    temp->next = NULL;
    return head;
}

struct Node *CheckOrAdd(struct Node *head, int element, int n)
{
    int i = 0;
    struct Node *dummy;
    dummy = head;
    while (dummy != NULL)
    {  
        if(dummy->data==element)
    {
        printf("Element found at index %d\n", i);
        break;
    }
        dummy = dummy->next;
        i++;
    }
    if (i == n)
    {
        head = AddAtEnd(head, element);
        printf("\n%d is not present,after adding %d at the end\n",element, element);
        Traverse(head);
    }
    
}

int main()
{
    int n, i, data, element;
    struct Node *head;
    printf("Enter no of nodes\n");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
        return head;
    printf("Enter 1st element to be inserted\n");
    scanf("%d", &data);
    head = AddAtEmpty(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter %d element to be inserted\n", i);
        scanf("%d", &data);

        head = AddAtEnd(head, data);
    }
    printf("\nAll lists are:\n");
    Traverse(head);

    printf("\nEnter an element to check whether it's present in list or not\n");

    fflush(stdin);
    scanf("%d", &element);

    CheckOrAdd(head, element, n);
}