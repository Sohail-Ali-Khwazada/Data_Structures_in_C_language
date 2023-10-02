//addatpos is slightly different.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* next;
    struct node* prev;
};

struct cDll {
    struct node* head;
};

char isEmpty (struct cDll* list) {
    if (list -> head == NULL) {
        return 1;
    }
    return 0;
}

void traverse (struct cDll* list) {
    struct node* temp  = list -> head;

    while (temp -> next != list -> head) {
        printf ("%d\t", temp -> val);
        temp = temp -> next;
    }
    
    printf ("%d\t", temp -> val);
    printf("\n");
}

void addFront (struct cDll* list, struct node* element) {
    
    element -> next = list -> head;
    element -> prev = (list -> head) -> prev;
    ((list -> head) -> prev) -> next = element;
    (list -> head) -> prev = element;
    list -> head = element;

}
void addEnd (struct cDll* list, struct node* element) {

    element -> next = list -> head;
    element -> prev = (list -> head) -> prev;
    ((list -> head) -> prev) -> next = element;
    (list -> head) -> prev = element;

}
void deleteFront (struct cDll* list) {

    struct node* temp = list -> head;
    list -> head = (list -> head) -> next;
    (list -> head) -> prev = temp -> prev;
    (temp -> prev) -> next = list -> head;
    free(temp);
}

void deleteEnd (struct cDll* list) {

    struct node* temp = (list -> head) -> prev;
    (((list -> head) -> prev) -> prev) -> next = list -> head;
    (list -> head) -> prev = ((list -> head) -> prev) -> prev;
    free(temp);
}

void addatpos (struct cDll* list, struct node* element, int pos) {
    if (pos == 1) {
        addFront(list,element);
        return;
    }
    struct node* prevNode = list -> head;
    struct node* curNode = (list -> head) -> next;
    int i = 1;
    pos--;
    while (i < pos && curNode != list -> head) {
        prevNode = prevNode -> next;
        curNode = curNode -> next;
        i++;
    }
    if (i == pos  && curNode == list -> head) {
        addEnd(list,element);
        return;
    }
    if (curNode == list -> head) {
        printf("Invalid position\n");
        return;
    }
        element -> next = curNode;
        element -> prev = prevNode;
        curNode -> prev = element;
        prevNode -> next = element;       
}

void deleteatpos (struct cDll* list, int pos) {
    if (pos == 1) {
        deleteFront(list);
        return;
    }
    struct node* prevNode = list -> head;
    struct node* curNode = (list -> head) -> next;
    int i = 1;
    pos--;
    while (i < pos && curNode != list -> head) {
        prevNode = prevNode -> next;
        curNode = curNode -> next;
        i++;
    }
    if (curNode == list -> head) {
        printf("Invalid position\n");
        return;
    }
    prevNode -> next = curNode -> next;
    (curNode -> next) -> prev = prevNode;
    free(curNode);
}


int main () {
    struct cDll list1,list2;
    struct cDll* listPointer;
    struct node* newNode;
    list1.head = list2.head = NULL;
    int listchoice,opchoice,pos;

    while (1) {
    do {
        printf("Enter the list that you want to operate on:\n1.List 1\n2.List 2\n");
        scanf("%d",&listchoice);
    } while (listchoice != 1 && listchoice != 2);

    if (listchoice == 1) {
        listPointer = &list1;
    } else {
        listPointer = &list2;
    }

    printf("----Menu----\n");
    printf("1.ADD FRONT\n2.ADD END\n3.DELETE FRONT\n4.DELETE END\n5.TRAVERSE\n6.ADDATPOS\n7.DELETEATPOS\n");
    scanf("%d",&opchoice);

    switch (opchoice) {
        case 1: newNode = (struct node*) malloc(sizeof(struct node));
                newNode -> next = newNode -> prev = NULL;
                printf("Enter the data:\n");
                scanf("%d",&(newNode -> val));
                if (isEmpty (listPointer) == 1) {
                    listPointer -> head = newNode;
                    (listPointer -> head) -> prev = (listPointer -> head) -> next = newNode;
                } else {
                    addFront (listPointer,newNode);
                }
        break;
        case 2: newNode = (struct node*) malloc(sizeof(struct node));
                newNode -> next = newNode -> prev = NULL;
                printf("Enter the data:\n");
                scanf("%d",&(newNode -> val));
                if (isEmpty (listPointer) == 1) {
                    listPointer -> head = newNode;
                    (listPointer -> head) -> prev = (listPointer -> head) -> next = newNode;
                } else {
                    addEnd (listPointer,newNode);
                }
        break;
        case 3: if (isEmpty (listPointer) == 1) {
                    printf("List is empty cannot delete\n");
                } else if ((listPointer -> head) -> next == listPointer -> head) {
                    listPointer -> head = NULL;
                } else {
                    deleteFront (listPointer);
                }
        break;
        case 4: if (isEmpty (listPointer) == 1) {
                    printf("List is empty cannot delete\n");
                } else if ((listPointer -> head) -> next == listPointer -> head) {
                    listPointer -> head = NULL;
                } else {
                    deleteEnd (listPointer);
                }
        break;
        case 5: if (isEmpty (listPointer) == 1) {
                    printf("List is empty cannot traverse\n");
                } else {
                    traverse (listPointer);
                }
        break;
        case 6: printf("Enter the position where you want to add the element\n");
                scanf("%d",&pos);
            
                if (pos < 1 || (isEmpty (listPointer) == 1 && pos != 1)) {
                    printf("INVALID POSITON\n");
                    break;
                }
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode -> next = newNode -> prev = NULL;
                printf("Enter the data: \n");
                scanf("%d",&(newNode -> val));
                if (isEmpty (listPointer) == 1 && pos == 1) {
                    listPointer -> head = newNode;
                    (listPointer -> head) -> prev = (listPointer -> head) -> next = newNode;
                } else  {
                    addatpos (listPointer, newNode,pos);
                    }

        break;
        case 7: if (isEmpty (listPointer) == 1) {
                    printf("List is empty cannot delete\n");
                    break;
                } 
                printf("Enter the position of element that you want to delete\n");
                scanf("%d",&pos);
                if (pos < 1) {
                    printf("Invalid position\n");
                } else if ((listPointer -> head) -> next == listPointer -> head  && pos == 1){
                        listPointer -> head = NULL;
                } else {
                    deleteatpos(listPointer,pos);
                }
        break;
        default: return 0;
    }

    }

}