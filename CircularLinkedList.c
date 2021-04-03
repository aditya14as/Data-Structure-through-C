#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
   struct Node *ptr=head;
    do
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}
struct Node* InsertAtStart(struct Node *head,int element){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=element;
    struct Node *p=head;

    do{
        p=p->next;
    }while(p->next!=head);
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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
    fourth->next = head;
    printf("\nCircular Linked List before Insertion\n");
    CircularLinkedListTraversal(head);

    printf("\nCircular Linked List after Insertion\n");
    head=InsertAtStart(head,70);
    CircularLinkedListTraversal(head);

}