#include<stdio.h>
#include<stdlib.h>

struct student {
    unsigned int roll,marks;
};

struct queue {
    int front,rear;
    unsigned int max;
    struct student *studarray;
};

char isEmpty(struct queue* q) {
    if (q ->front == q->rear) {
        return 1;
    }
    return 0;
}

char isFull(struct queue* q) {
    if (q ->front ==( q->rear + 1) % (q ->max)) {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue* q, struct student* s) {
    q ->rear = (q ->rear + 1) % (q ->max);
    q->studarray[q ->rear] = *s;
}

struct student dequeue(struct queue* q) {
    q ->front = (q ->front + 1) % (q ->max);
    return  q->studarray[q ->front];
}

struct student* peek (struct queue* q, int choice) {
    if (choice == 1) {
        return &(q->studarray[(q->front + 1) % (q->max)]);
    }
    return &(q->studarray[q ->rear]);
}

int main() {
    struct queue q1,q2;
    struct student s;
    struct queue *pointertoqueue;
    q1.front = q2.front = q1.rear = q2.rear = 0;
    int queuechoice,opchoice,peekchoice;

    printf("Enter the maximum number of students info for Queue 1 and Queue 2 respectively\n");
    scanf("%d%d",&(q1.max),&(q2.max));
    q1.max++;
    q2.max++;
    q1.studarray = (struct student*) malloc((q1.max) * sizeof(struct student));
    q2.studarray = (struct student*) malloc((q2.max) * sizeof(struct student));

    while (1) {
        do {
            printf("Enter which queue you want to operate on:\n1.Queue 1\n2.Queue 2\n");
            scanf("%d",&queuechoice);
        } while(queuechoice != 1 && queuechoice != 2);
        if (queuechoice == 1) {
            pointertoqueue = &q1;
        } else {
            pointertoqueue = &q2;
        }

        printf("-----Menu-----\n");
        printf("1.Check if Queue is empty or not\n2.Check if is full or not\n3.Enqueue\n4.Dequeue\n5.Peek\n");
        scanf("%d",&opchoice);

        switch (opchoice) {
            case 1: if (isEmpty(pointertoqueue) == 1) {
                printf("Queue is empty\n");
            } else {
                printf("Queue is not empty\n");
            }
            break;
            
            case 2: if (isFull(pointertoqueue) == 1) {
                printf("Queue is Full\n");
            } else {
                printf("Queue is not Full\n");
            }
            break;
            
            case 3: if (isFull(pointertoqueue) == 1) {
                printf("Queue is full cannot enqueue\n");
            } else {
                printf("Enter the roll number and marks of the student\n");
                scanf("%d%d",&(s.roll),&(s.marks));
                Enqueue(pointertoqueue,&s);
            }
            break;

            case 4: if (isEmpty(pointertoqueue) == 1) {
                printf("Queue is empty cannot dequeue\n");
            } else {
                s = dequeue(pointertoqueue);
                printf("Deleted record:Roll no: %d, Marks: %d\n",s.roll,s.marks);
            } 
            break;

            case 5: if (isEmpty(pointertoqueue) == 1) {
                printf("Queue is empty cannot peek\n");
            } else {
                do {
                    printf("Choose do you want peek at front or end\n1.Peek at front\n2.Peek at end\n");
                    scanf("%d",&peekchoice);
                } while(peekchoice != 1 && peekchoice != 2);
                s = *(peek(pointertoqueue,peekchoice));
                printf("Record:Roll no: %d,Marks: %d\n",s.roll,s.marks);
            }
            break;

            default: return 0;
        }   
    }
}