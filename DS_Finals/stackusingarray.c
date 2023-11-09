#include<stdio.h>
#include<stdlib.h>

struct student {
    unsigned int roll;
    unsigned int score;
};

struct stack {
    unsigned int max,top;
    struct student* studarray;
};

char isEmpty(struct stack* s) {
    if(s ->top == 0) {
        return 1;
    }
    return 0;
}

char isFull(struct stack* s) {
    if (s ->top == s->max) {
        return 1;
    }
    return 0;
}

void push(struct stack *s,struct student stu) {
    s->top++;
    s->studarray[s->top] = stu;
    
}

struct student pop(struct stack *s) {
    struct student temp = s->studarray[s->top];
    s->top--;
    return temp;
}

struct student* peek(struct stack* s) {
    return &(s->studarray[s->top]);
}

int main() {
    struct stack s1,s2;
    struct stack* stackpointer;
    struct student stu;
    s1.top = s2.top = 0;
    int stackchoice,opchoice,peekchoice;
    printf("Enter the capacity for stack 1 and stack 2 respectively\n");
    scanf("%d%d",&s1.max,&s2.max);
    s1.studarray = (struct student*)malloc((s1.max + 1)*sizeof(struct student));
    s2.studarray = (struct student*)malloc((s2.max + 1)*sizeof(struct student));

    while(1) {
        do {
            printf("Choose:\n1.Stack 1\n2.Stack 2\n");
            scanf("%d",&stackchoice);
        } while(stackchoice != 1 && stackchoice != 2);
        if(stackchoice == 1) {
            stackpointer = &s1;
        } else {
            stackpointer = &s2;
        }

        printf("----Menu----\n");
        printf("1.Check Empty\n2.Check Full\n3.Push\n4.Pop\n5.Peek\n");
        scanf("%d",&opchoice);

        switch(opchoice) {
            case 1:
                if(isEmpty(stackpointer) == 1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 2:
                if(isFull(stackpointer) == 1) {
                    printf("Stack is Full\n");
                } else {
                    printf("Stack is not Full\n");
                }
                break;
            case 3:
                if(isFull(stackpointer) == 1) {
                    printf("Cannot push the stack is already full\n");
                } else {
                    printf("Enter the Roll no and marks of a student respectively\n");
                    scanf("%d%d",&stu.roll,&stu.score);
                    push(stackpointer,stu);
                } 
                break;
            case 4:
                if(isEmpty(stackpointer) == 1) {
                    printf("Cannot pop the stack is empty\n");
                } else {
                    stu = pop(stackpointer);
                    printf("Popped Element:\nRoll no = %d\nScore = %d\n",stu.roll,stu.score);   
                } 
                break;
            case 5:
                if(isEmpty(stackpointer) == 1) {
                    printf("Cannot peek the stack is empty\n");
                } else {
                    stu = *peek(stackpointer);
                    printf("Element:\nRoll no = %d\nScore = %d\n",stu.roll,stu.score);   
                } 
                break;
            default: 
                printf("Invalid Choice");
                return 0;
        }
    }

}