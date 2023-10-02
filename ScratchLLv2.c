//IMPLEMENTATION OF SINGLY LINKED LIST.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};
struct SLL {
    struct Node* head;
};

void traverse(struct Node *hd) {
    while(hd != NULL) {
        printf("%d ",(*hd).val);
        hd = (*hd).next;
    }
    printf("\n");
}

int getSize(struct Node *hd) {
    if(hd == NULL) {
        return 0;
    }
    int count = 0;
    while (hd != NULL) {
        hd = (*hd).next;
        count++;
    }
    return count;
}

void addFirst(struct Node **hd, struct Node *element) {
    (*element).next = *hd;
    *hd = element;

}

void addEnd (struct Node **hd, struct Node *element) {
    // if(*hd == NULL) {
    //     *hd = element;
    //     return;
    // }
    struct Node *temp;
    temp = *hd;
    while ((*temp).next != NULL) {
        temp = (*temp).next;
    }
    (*temp).next = element;
}

void deleteFirst(struct Node **hd) {
    struct Node *temp = *hd;
    *hd = (*(*hd)).next;
    free(temp);
}

void deleteEnd(struct Node **hd) {
    // if((*(*hd)).next == NULL) {
    //     *hd = NULL;
    //     return;
    // }
    struct Node *secondLast = *hd;
    struct Node *Last = (*(*hd)).next;
    while((*Last).next != NULL) {
        Last = (*Last).next;
        secondLast =(*secondLast).next;
    }
    (*secondLast).next = NULL;
    free(Last);
}

void addAtpos(struct Node **hd,int index,struct Node* element) {
    if (index == 0) {
        addFirst(hd,element);
        return;
    }
    struct Node *curNode = *hd;
    int i = 1;
    while (i < index) {
        curNode = (*curNode).next;
        i++;
    }
    struct Node *nextNode = (*curNode).next;
    (*curNode).next = element;
    (*element).next = nextNode;
}

void deleteAtpos(struct Node **hd, int index) {
    if (index == 0) {
        deleteFirst(hd);
        return;
    }
    struct Node* prevNode = *hd;
    struct Node* currNode =(*(*hd)).next;
    int i = 1;
    while (i < index) {
        prevNode =(*prevNode).next;
        currNode =(*currNode).next;
        i++;
    }
    (*prevNode).next = (*currNode).next;
    free(currNode);
}

int main () {
    struct SLL list1,list2;
    struct SLL *s1;
    struct Node *newNode;
    list1.head = list2.head = NULL;
    int choice,lchoice, flag = 1;
    int index,size;
    while(1) {
        lchoice = 0;
        while(lchoice != 1 && lchoice != 2) {
            printf("Choose the list:\n1.FOR LIST1\n2.FOR LIST2\n");
            scanf("%d",&lchoice);
        }
        if (lchoice == 1) {
            s1 = &list1;
        } else {
            s1 = &list2;
        }
        printf("\n1.ADD FIRST\n2.ADD END\n3.TRAVERSE\n4.DELETE FIRST\n5.DELETE END\n6.ADD AT SPECIFIC POSITION\n7.DELETE A SPECIFIC NODE\n8.Size\n\n");
        printf("Enter choice: \n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
            newNode = (struct Node*) malloc(sizeof(struct Node));
            (*newNode).next = NULL;
            printf("Enter the data: \n");
            scanf("%d",&(*newNode).val);
            addFirst(&(s1->head),newNode);
            break;

            case 2: 
            newNode = (struct Node*) malloc(sizeof(struct Node));
            (*newNode).next = NULL;
            printf("Enter the data: \n");
            scanf("%d",&(*newNode).val);
            if(s1->head == NULL) {
                addFirst(&(s1->head),newNode);
            } else {
            addEnd(&(s1->head),newNode);
            }
            break;

            case 3:
            if(s1->head == NULL) {
                printf("List is empty\n");
            }else {
            traverse(s1->head);
            }
            break;

            case 4: 
            if (s1->head == NULL) {
                printf("LIST IS EMPTY HENCE CANNOT PERFORM DELETE OPERATION\n");
            } else {
                deleteFirst(&(s1->head));
            }
            break;

            case 5:
            if(s1->head == NULL) {
                printf("LIST IS EMPTY HENCE CANNOT PERFORM DELETE OPERATION\n");
            } else {
                if((*(s1->head)).next == NULL) {
                s1->head = NULL;
                } else {
                deleteEnd(&(s1->head));
                }
            }
            break;

            case 6:
            // int index;
            printf("Enter the index where you want to add the element\n");
            scanf("%d",&index);
            size = getSize(s1->head);
            if (index < 0 || index > size) {
                printf("INVALID POSITON\n");
            } else {
                newNode = (struct Node *)malloc(sizeof(struct Node));
                (*newNode).next = NULL;
                printf("Enter the data: \n");
                scanf("%d",&(*newNode).val);
                addAtpos(&(s1->head),index,newNode);
            }
            break;

            case 7:
            if (s1->head == NULL) {
                printf("LIST IS EMPTY HENCE CANNOT PERFORM DELETE OPERATION\n");
                break;
            }
            printf("Enter the index of the Node that you want to delete\n");
            scanf("%d",&index);
            size = getSize(s1->head);
            if (index < 0 || index > size) {
                printf("INVALID POSITON\n");
            } else {
                deleteAtpos((&(s1->head)),index);
            }
            break;

            case 8:
            printf("Size = %d\n",getSize(s1->head));
            break;

            default:
            flag = 0;
            break;
        }
        if(flag == 0) {
            break;
        }
    }
    
    return 0;
}