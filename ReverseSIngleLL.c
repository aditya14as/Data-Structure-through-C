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
        printf("%d\t", tra->data);
        tra = tra->next;
    }
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
        if (dummy->data == element)
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
        printf("\n%d is not present,after adding %d at the end\n", element, element);
        Traverse(head);
    }
}
struct Node *Reverse(struct Node *head)
{
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *upcoming;
    while(current!=NULL){
        upcoming=current->next;
        current->next=prev;
        prev=current;
        current=upcoming;

    }
    head=prev;
    Traverse(head);
}

struct Node *main()
{
    int n, i, data, element,choice;
    struct Node *head;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
        return head;
    printf("Enter element 1 to be inserted: ");
    scanf("%d", &data);
    head = AddAtEmpty(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter element %d to be inserted: ", i);
        scanf("%d", &data);

        head = AddAtEnd(head, data);
    }
    

    while(1){
        printf("\n1.Display List\n");
        printf("2.Check whether given no is present or not\n");
        printf("3.Reverse\n");
        printf("4.Quit\n");
        printf("\nEnter your choice: ");
       
        scanf("%d",&choice);
    switch(choice){

     case 1:
       printf("\nAll lists are:\t");
       Traverse(head);
       break;

     case 2:
       printf("\nEnter a element to check whether it's present in list or not: ");
       fflush(stdin);
       scanf("%d", &element);
       CheckOrAdd(head, element, n);
       break;

     case 3:
       Reverse(head);
       break;

     case 4:
      exit(1);

     default:
      printf("Wrong Choice");

    }
  }
}