#include <stdio.h>
#include <stdlib.h>

struct student
{
    unsigned int roll;
    struct student *next;
};

struct queue
{
    struct student *front;
    struct student *rear;
};

char isEmpty(struct queue *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *q, struct student *s)
{
    struct student *temp = q->rear;
    temp->next = s;
    q->rear = s;
}

struct student *Dequeue(struct queue *q)
{
    struct student* temp = q->front;
    q->front = temp ->next;
    return temp;
}

struct student *peek(struct queue *q, int choice)
{
    if(choice == 1) {
        return q->front;
    }
    return q->rear;
}

int main()
{
    struct student *newNode;
    struct queue q;
    int opchoice,peekchoice;
    q.front = q.rear = NULL;

    while (1)
    {
        printf("----Menu----\n");
        printf("1.Check Empty\n2.Enqueue\n3.Dequeue\n4.Peek\n");
        scanf("%d", &opchoice);

        switch (opchoice)
        {
        case 1:
            if (isEmpty(&q) == 1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 2:
            newNode = (struct student *)malloc(sizeof(struct student));
            newNode->next = NULL;
            printf("Enter the Roll no\n");
            scanf("%d", &(newNode->roll));
            if (isEmpty(&q) == 1)
            {
                q.front = q.rear = newNode;
            }
            else
            {
                Enqueue(&q, newNode);
            }
            break;
        case 3:
            if (isEmpty(&q) == 1)
            {
                printf("Cannot Dequeue from an empty queue\n");
            }
            else
            {
                struct student* temp = Dequeue(&q);
                printf("Dequeued Element:\nRoll no = %d\n", temp ->roll);
            }
            break;
        case 4:
            if (isEmpty(&q) == 1)
            {
                printf("Cannot peek from an empty queue\n");
            }
            else
            {
                do {
                    printf("1.To peek from front\n2.To peek from end\n");
                    scanf("%d",&peekchoice);
                } while(peekchoice != 1 && peekchoice != 2);
                struct student* temp = peek(&q,peekchoice);
                printf("Element:\nRoll no = %d\n", temp->roll);
            }
            break;
        default:
            printf("Invalid Choice\n");
            return 0;
        }
    }
}