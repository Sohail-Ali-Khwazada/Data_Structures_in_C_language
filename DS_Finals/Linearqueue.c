#include <stdio.h>
#include <stdlib.h>

struct student
{
    unsigned int roll, score;
};

struct queue
{
    unsigned int max;
    int front, rear;
    struct student *studarray;
};

char isEmpty(struct queue *q)
{
    if (q->front > q->rear)
    {
        return 1;
    }
    return 0;
}

char isFull(struct queue *q)
{
    if (q->rear == q->max - 1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *q, struct student stu)
{
    q->rear++;
    q->studarray[q->rear] = stu;
}

struct student Dequeue(struct queue *q)
{
    struct student temp = q->studarray[q->front];
    q->front++;
    return temp;
}

struct student *peek(struct queue *q, int choice)
{
    if(choice == 1) {
        return &(q->studarray[q->front]);
    }
    return &(q->studarray[q->rear]);
}

int main()
{
    struct student stu;
    struct queue q1, q2;
    struct queue *queuepointer = NULL;
    int queuechoice, opchoice,peekchoice;
    q1.front = q2.front = 0;
    q1.rear = q2.rear = -1;

    printf("Enter the capacity for queue 1 and queue 2 respectively\n");
    scanf("%d%d", &q1.max, &q2.max);
    q1.studarray = (struct student *)malloc((q1.max) * sizeof(struct student));
    q2.studarray = (struct student *)malloc((q2.max) * sizeof(struct student));

    while (1)
    {
        do
        {
            printf("Choose:\n1.Queue 1\n2.Queue 2\n");
            scanf("%d", &queuechoice);
        } while (queuechoice != 1 && queuechoice != 2);
        if (queuechoice == 1)
        {
            queuepointer = &q1;
        }
        else
        {
            queuepointer = &q2;
        }

        printf("----Menu----\n");
        printf("1.Check Empty\n2.Check Full\n3.Enqueue\n4.Dequeue\n5.Peek\n");
        scanf("%d", &opchoice);

        switch (opchoice)
        {
        case 1:
            if (isEmpty(queuepointer) == 1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 2:
            if (isFull(queuepointer) == 1)
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is not Full\n");
            }
            break;
        case 3:
            if (isFull(queuepointer) == 1)
            {
                printf("Queue is Full and hence cannot perform enqueue operation\n");
            }
            else
            {
                printf("Enter the Roll no and marks of a student respectively\n");
                scanf("%d%d", &stu.roll, &stu.score);
                Enqueue(queuepointer, stu);
            }
            break;
        case 4:
            if (isEmpty(queuepointer) == 1)
            {
                printf("Cannot Dequeue from an empty queue\n");
            }
            else
            {
                stu = Dequeue(queuepointer);
                printf("Dequeued Element:\nRoll no = %d\nScore = %d\n", stu.roll, stu.score);
            }
            break;
        case 5:
            if (isEmpty(queuepointer) == 1)
            {
                printf("Cannot peek from an empty queue\n");
            }
            else
            {
                do {
                    printf("Enter:1.To peek from front\n2.To peek from end\n");
                    scanf("%d",&peekchoice);
                } while(peekchoice != 1 && peekchoice != 2);
                stu = *peek(queuepointer,peekchoice);
                printf("Element:\nRoll no = %d\nScore = %d\n", stu.roll, stu.score);
            }
            break;
        default:
            printf("Invalid Choice");
            return 0;
        }
    }
    return 0;
}