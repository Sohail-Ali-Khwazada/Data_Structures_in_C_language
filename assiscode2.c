#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct stack
{
    int top;
    char *array;
};
int getPrecedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
void push(struct stack *x, char ch);
char pop(struct stack *x);
void main()
{
    struct stack s;
    s.array = NULL;
    s.top = -1;
    char str[20];
    int len, i = 0;
    printf("Enter a Infix Expression: ");
    scanf("%s", str);
    len = strlen(str);
    s.array = (char *)malloc(len * sizeof(char));
    printf("\nPostfix Expression: \n");
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(&s, str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            while ((s.array[s.top] != '(' && str[i] == ')') || (s.array[s.top] != '{' && str[i] == '}') || (s.array[s.top] != '[' && str[i] == ']'))
            {
                printf("%c", pop(&s));
            }
            pop(&s);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '%')
        {
            if (s.top != -1)
            {
                if (getPrecedence(s.array[s.top]) >= getPrecedence(str[i]))
                {
                    printf("%c", pop(&s));
                }
            }
            push(&s, str[i]);
        }
        else
            printf("%c", str[i]);
        i++;
    }
    while (s.top != -1)
        printf("%c", pop(&s));
}
void push(struct stack *x, char ch)
{
    (*x).top++;
    (*x).array[(*x).top] = ch;
}
char pop(struct stack *x)
{
    char temp = (*x).array[(*x).top];
    (*x).top--;
    return temp;
}