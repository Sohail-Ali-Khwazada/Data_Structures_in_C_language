#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1) {
        return -1;
    }
    return stack[top--];
}

char matchingbraces(char brace) {
  switch(brace) {
    case '}':
      return '{';
    case ']':
      return '[';
    case ')':
      return '(';
    default:
      return -1;
  }
}


char checkexp(char *e) {
    while(*e != '\0') {
        if(*e == '{' || *e == '[' ||*e == '(') {
            push(*e);
        } else if (*e == '}' || *e == ']' ||*e == ')') {
            if (top == -1 || matchingbraces(*e) != stack[top]) {
                return 0;
            }
            pop();  
        }
        e++;
    }
    if(top == -1) {
        return 1;
    }
    return 0;

}



int main() {
    char exp[MAX],*e;
    printf("Enter the expression\n");
    scanf("%s", exp);
    e = exp;


    if(checkexp(e) == 1) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }
    return 0;
}