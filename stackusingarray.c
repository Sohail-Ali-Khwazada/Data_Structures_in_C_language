//Implementation of ADT Stack using Array.
#include<stdio.h>
#include<stdlib.h>

struct student {
    unsigned int roll;
    unsigned int score;
};

struct stack {
    unsigned int max;
    unsigned int top;
    struct student* studarray;
};

char isEmpty(struct stack* s) {
    if((*s).top == 0) {
        return 1;
    } else {
        return 0;
    }
}

char isFull(struct stack* s) {
    if((*s).top ==(*s).max) {
        return 1;
    } else {
        return 0;
    }
}

struct student* peek(struct stack* s) {
    return &((*s).studarray[(*s).top]);
}

void push(struct stack *s, struct student a) {
    (*s).top++;
    (*s).studarray[(*s).top] = a;
}

struct student pop(struct stack *s) {
    struct student temp = (*s).studarray[(*s).top];
    (*s).top--;
    return temp;
}

int main() {
    struct student stu;
    struct stack s;
    int choice,flag = 1;
    printf("Enter max no. of students: ");
    scanf("%d",&s.max);
    s.top = 0;
    s.studarray = (struct student *)malloc((s.max+1)*sizeof(struct student));
    while(1)
    {
        printf("Enter choice 1.Push 2.Pop 3.Peek 4.Check if stack is empty or not 5.Check if stack is full or not\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(isFull(&s) != 1){
                printf("Enter Roll number and marks\n");
                scanf("%u%u",&stu.roll,&stu.score);
                push(&s,stu);
            }
            else{
                printf("Cannot push into the stack anymore\n");
            }
            break;
            case 2: if(isEmpty(&s) != 1){
                stu = pop(&s);
                printf("Roll no. : %u \t Marks : %u\n",stu.roll,stu.score);
            }
            else{
                printf("Cannot pop from an empty stack\n");
            }
            break;
            case 3: if(isEmpty(&s) != 1){
                stu = *(peek(&s));
                printf("Roll no. : %u \t Marks : %u \n",stu.roll,stu.score);
            }
            else{
                printf("Cannot peek into an empty stack\n");
            }
            break;
            case 4: if(isEmpty(&s) == 1){
                printf("Stack is empty.\n");
            }
            else{
                printf("Stack is not empty.\n");
            }
            break;
            case 5: if(isFull(&s) == 1){
                printf("Stack is full.\n");
            }
            else{
                printf("Stack is not full.\n");
            }
            break;
            default :flag = 0;
            break;
        }
        if(flag == 0) break;
    }
    return 0;
}