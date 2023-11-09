#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct sll
{
    struct node *head;
};

void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void addfront(struct sll *list, struct node *newNode)
{
    newNode->next = list->head;
    list->head = newNode;
}

void addend(struct sll *list, struct node *newNode)
{
    struct node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addatpos(struct sll *list, struct node *newNode, int pos)
{
    struct node *temp = list->head;
    pos--;
    while (temp != NULL && pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL)
    {
        printf("Position is greater than the size of the list and hence cannot add the element\n");
        return;
    } 
    newNode->next = temp->next;
    temp->next = newNode;
}

struct node *deletefront(struct sll *list)
{
    struct node *temp = list->head;
    list->head = temp->next;
    return temp;
}

struct node *deleteend(struct sll *list)
{
    struct node *temp = list->head;
    if (temp->next == NULL)
    {
        list->head = NULL;
        return temp;
    }
    struct node *temp2 = temp->next;

    while (temp2->next != NULL)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    return temp2;
}

struct node *deleteatpos(struct sll *list, int pos)
{
    struct node* temp = list->head;
    
    pos--;
    while(temp != NULL && pos != 1) {
        temp = temp ->next;
        pos--;
    }
    if (temp == NULL) {
        printf("Position is greater than the size of the list and hence cannot delete the element\n");
        return NULL;
    }
    struct node* temp2 = temp ->next;
    temp -> next = temp2 -> next;
    return temp2;

}

int main()
{
    struct sll list1, list2;
    struct sll *listpointer = NULL;
    struct node *newNode;
    int listchoice, opchoice,pos;
    list1.head = NULL;
    list2.head = NULL;

    while (1)
    {
        do
        {
            printf("Choose List\n1.List1\n2.List2\n");
            scanf("%d", &listchoice);
        } while (listchoice != 1 && listchoice != 2);

        if (listchoice == 1)
        {
            listpointer = &list1;
        }
        else
        {
            listpointer = &list2;
        }

        printf("----Menu----\n");
        printf("1.Traverse\n2.Add at front\n3.Add at End\n4.Delete at First\n5.Delete at End\n6.Add at pos\n7.Delete at pos\n");
        scanf("%d", &opchoice);

        switch (opchoice)
        {
        case 1:
            if (listpointer->head == NULL)
            {
                printf("List is Empty cannot traverse\n");
                break;
            }
            traverse(listpointer->head);
            break;
        case 2:
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->next = NULL;
            printf("Enter the value\n");
            scanf("%d", &(newNode->val));
            addfront(listpointer, newNode);
            break;
        case 3:
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->next = NULL;
            printf("Enter the value\n");
            scanf("%d", &(newNode->val));
            if (listpointer->head == NULL)
            {
                listpointer->head = newNode;
                break;
            }
            addend(listpointer, newNode);
            break;
        case 4:
            if (listpointer->head == NULL)
            {
                printf("List is Empty cannot delete\n");
                break;
            }
            printf("Deleted Element: %d\n", (deletefront(listpointer))->val);
            break;
        case 5:
            if (listpointer->head == NULL)
            {
                printf("List is Empty cannot delete\n");
                break;
            }
            printf("Deleted Element: %d\n", (deleteend(listpointer))->val);
            break;
        case 6:
            printf("Enter the position at which you want to add the element\n");
            scanf("%d", &pos);
            if (pos < 1)
            {
                printf("Invalid position");
                break;
            }
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->next = NULL;
            printf("Enter the value\n");
            scanf("%d", &(newNode->val));
            if (pos == 1)
            {
                addfront(listpointer, newNode);
            }
            else
            {
                addatpos(listpointer, newNode, pos);
            }
            break;
        case 7:
           
            if (listpointer->head == NULL)
            {
                printf("List is Empty cannot delete\n");
                break;
            }
            printf("Enter the position of element that you want to delete\n");
            scanf("%d", &pos);
            if (pos < 1)
            {
                printf("Invalid position");
                break;
            }
            if(pos == 1) {
                printf("Deleted Element: %d\n", (deletefront(listpointer))->val);
            } else {
                struct node* temp = deleteatpos(listpointer,pos);
                if (temp != NULL)
                printf("Deleted Element: %d\n", (temp)->val);
            }
            break;
        default:
            printf("Invalid Choice");
            return 0;
        }
    }
}