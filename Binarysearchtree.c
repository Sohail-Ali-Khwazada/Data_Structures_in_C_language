//IMPLEMENTATION OF BINARY SEARCH TREE.
#include<stdio.h>
#include<stdlib.h>

struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
};

struct tree {
    struct treenode *root;
};

void traverse (struct treenode *pointertocurNode) {
    //inorder traversal
    if (pointertocurNode == NULL){
        return;
    }
    traverse(pointertocurNode -> left);
    printf("%d ",pointertocurNode -> val);
    traverse(pointertocurNode -> right);   

}

void insert (struct treenode *pointertocurNode, struct treenode *element) {
    if (element -> val <= pointertocurNode -> val ) {
        if (pointertocurNode -> left != NULL) {
            insert(pointertocurNode -> left, element);
        } else {
            pointertocurNode -> left = element;
            return;
        }
    } else {
        if (pointertocurNode -> right != NULL) {
            insert(pointertocurNode -> right, element);
        } else {
            pointertocurNode -> right = element;
            return;
        }

    }
}

struct treenode* search(struct treenode *pointertocurNode, int element) {
    if (element == pointertocurNode -> val) {
        return pointertocurNode;
    }
    if (element <= pointertocurNode -> val ) {
        if (pointertocurNode -> left != NULL) {
            search(pointertocurNode -> left, element);
        } else {
            return NULL;
        }
    } else {
        if (pointertocurNode -> right != NULL) {
            search(pointertocurNode -> right, element);
        } else {
            return NULL;
        }

    }
}

int main () {
    struct tree tre1, tre2;
    struct tree *pointertotree;
    struct treenode *newNode;
    tre1.root = tre2.root = NULL;
    int treechoice,opchoice,searchval;

    while (1) {
        do {
        printf("\nEnter the Tree that you want to operate on:\n1.TREE 1\n2.TREE 2\n");
        scanf("%d",&treechoice);
    } while (treechoice != 1 && treechoice != 2);

    if (treechoice == 1) {
        pointertotree = &tre1;
    } else {
        pointertotree = &tre2;
    }

    printf("----Menu----\n");
    printf("1.Insert\n2.Delete\n3.Traverse\n4.Search\n");
    scanf("%d",&opchoice);

    switch (opchoice) {
        case 1: newNode = (struct treenode*)malloc(sizeof(struct treenode));
                newNode -> left = newNode -> right = NULL;
                printf("Enter a data\n");
                scanf("%d",&(newNode -> val));
                if (pointertotree -> root == NULL) {
                    pointertotree -> root = newNode;
                } else {
                    insert(pointertotree -> root, newNode);
                }
        break;
        case 2:
        break;
        case 3: if (pointertotree -> root == NULL) {
                    printf("There are no elements in a tree to traverse\n");
                } else {
                    traverse(pointertotree -> root);
                }
        break;
        case 4: if (pointertotree -> root == NULL) {
                    printf("Thera are no elements in a tree hence cannot perform search operarion.\n");
                    break;
                } 
                printf("Enter a value that you want to search\n");
                scanf("%d",&searchval);
                if (search(pointertotree -> root, searchval) == NULL) {
                    printf("Element is not present in the tree.\n");
                } else {
                    printf("Element %d exists in the tree.\n",searchval);
                }
        break;
        
        default:
        return 0;
    }
    }
}