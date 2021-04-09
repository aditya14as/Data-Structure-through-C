#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void isEmptyisFull(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else if (ptr->top == ptr->size - 1)
    {
        printf("Stack is Full");
    }
    else
    {
        printf("Stack is neither empty nor full");
    }
}

void push(struct Stack *ptr, int x)
{
    if (ptr->top == ptr->size - 1)
        printf("Stack Overflow, cannot push %d to the stack\n", x);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = x;
    }
}

void Display(struct Stack *ptr)
{
    int i;
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (i = ptr->top; i >= 0; i--)
        {
            printf("%d\n", ptr->arr[i]);
        }
    }
}

int pop(struct Stack *ptr)
{
    int x;
    if (ptr->top == -1)
    {
        printf("Stack Underflow, cannot pop element\n");
    }
    else
    {
        x = ptr->arr[ptr->top];
        ptr->top--;
    }
    return x;
}

int peek(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int stackTop(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return ptr->arr[0];
    }
}

int main()
{
    int choice, n, i, element;
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    isEmptyisFull(s);

    while (1)
    {
        printf("\n1. Check whether stack is empty or full\n");
        printf("2. Push\n");
        printf("3. Display all stack elements\n");
        printf("4. Pop\n");
        printf("5. Peek\n");
        printf("6. StackTop\n");
        printf("7. StackBottom\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            isEmptyisFull(s);
            break;

        case 2:
            printf("Enter no of element to be pushed: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter an element that are to be pushed at index %d is: ", i);
                scanf("%d", &element);
                push(s, element);
            }
            break;

        case 3:
            Display(s);
            break;

        case 4:
            element = pop(s);
            printf("Popped item is: %d\n", element);
            break;

        case 5:
            printf("Peeked item is: %d\n", peek(s));
            break;

        case 6:
            printf("Element at the top is: %d\n", stackTop(s));
            break;

        case 7:
            printf("Element at the bottom is: %d\n", stackBottom(s));
            break;

        case 8:
            exit(1);

        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}