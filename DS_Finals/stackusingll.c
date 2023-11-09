// Implementation of stack using singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    struct student *next;
};

struct stack
{
    struct student *top;
};

char isEmpty(struct stack *s)
{
    if ((*s).top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct student *peek(struct stack *s)
{
    return (*s).top;
}

void push(struct stack *s, struct student *element)
{
    (*element).next = (*s).top;
    (*s).top = element;
}

struct student* pop(struct stack *s)
{
    struct student* temp = (*s).top;
    (*s).top = (*((*s).top)).next;
    return temp;
}

int main()
{
    struct stack stack1, stack2;
    struct stack *stackpointer = NULL;
    struct student *newstudent;
    stack1.top = stack2.top = NULL;
    int stackchoice, opchoice;

    while (1)
    {
        do
        {
            printf("Choose the Stack:\n1.FOR Stack1\n2.FOR STACK2\n");
            scanf("%d", &stackchoice);
        } while (stackchoice != 1 && stackchoice != 2);
        if (stackchoice == 1)
        {
            stackpointer = &stack1;
        }
        else
        {
            stackpointer = &stack2;
        }
        printf("Enter choice\n1.Push\n2.Pop\n3.Peek\n4.Check if stack is empty or not\n");
        scanf("%d", &opchoice);

        switch (opchoice)
        {
        case 1:
            newstudent = (struct student *)malloc(sizeof(struct student));
            printf("Enter the roll no of a student\n");
            scanf("%d", &(*newstudent).roll);
            (*newstudent).next = NULL;
            push(stackpointer, newstudent);
            break;

        case 2:
            if (isEmpty(stackpointer) != 1)
            {   struct student *temp = pop(stackpointer);
                printf("Popped element is %d\n",temp->roll);
            }
            else
            {
                printf("CANNOT POP ELEMENT FROM AN EMPTY STACK\n");
            }
            break;
        case 3:
            if (isEmpty(stackpointer) != 1)
            {
                struct student *temp = peek(stackpointer);
                printf("Roll no: %d\n", (*temp).roll);
            }
            else
            {
                printf("CANNOT Peek ELEMENT FROM AN EMPTY STACK\n");
            }
            break;
        case 4:
            if (isEmpty(stackpointer) == 1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        default:
            return 0;
        }
    }
}