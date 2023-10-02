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
//RECURSIVE APPROACH
struct treenode* search_recursive(struct treenode *pointertocurNode, int element) {
    if (pointertocurNode == NULL) {
        return NULL;
    }
    if (element == pointertocurNode -> val) {
        return pointertocurNode;
    } else if (element <= pointertocurNode -> val ) {
            return search_recursive(pointertocurNode -> left, element);
    } else {
            return search_recursive(pointertocurNode -> right, element);
        }
}


//ITERATIVE APPROACH
struct treenode* search_iterative(struct treenode *pointertocurNode, int element) {
    while (pointertocurNode != NULL) {
        if (element == pointertocurNode -> val) {
            return pointertocurNode;
        } else if (element <= pointertocurNode -> val ) {
            pointertocurNode = pointertocurNode -> left;
        } else {
            pointertocurNode = pointertocurNode -> right;
        }
    }
    return NULL;  
}


int main () {
    struct tree tre1, tre2;
    struct tree *pointertotree;
    struct treenode *newNode,*temp;
    tre1.root = tre2.root = NULL;
    int treechoice,opchoice,searchval,searchchoice;

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
                do {
                    printf("Choose:\n1.Recursive search\n2.Iteraive search\n");
                    scanf("%d",&searchchoice);
                } while (searchchoice != 1 && searchchoice != 2);

                if (searchchoice == 1) {
                    temp = search_recursive(pointertotree -> root, searchval);
                } else {
                    temp = search_iterative(pointertotree -> root, searchval);
                }

                if (temp == NULL) {
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