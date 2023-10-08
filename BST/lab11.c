#include <stdlib.h>
#include <stdio.h>
#include "lab11.h"

typedef struct Node {
    Node * left, * right;
    int data;
} Node;

struct BST 
{
    /* data */
    Node * root;
    int size;
};

/* Helper Functions */

// This function creates a new tree node with the provided integer
Node * createNode(int data) {

    Node * p = malloc(sizeof(Node));

    if(p) {
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    }

    return(p);

}

// This function inserts a new node into the tree
void BSTInsert(Node * newNode, Node * root) {

    if(!root) {
        root = newNode;
    }

    if(newNode->data < root->data) {
        BSTInsert(newNode, root->left);
    }

    else if(newNode->data > root->data) {
        BSTInsert(newNode, root->right);
    }

}

// this function prints the data in the tree in descending order (largest to smallest)
void descendingOrderPrintBST(Node * root) {

    if(!root) return;
    descendingOrderPrintBST(root->right);
    printf("%d\n", root->data);
    descendingOrderPrintBST(root->left);

}

// This function frees all the nodes in a tree
void freeTree(Node * root) {

    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);

}   


/* Lab Functions */

// this function initializes a BST, it takes no parameters and returns a BST pointer
BST * initBST() {

    BST * tree = malloc(sizeof(BST));

    if(tree) {
        tree->root = NULL;
        tree->size = 0;
    }
    
    return tree;

}

// this function creates a new node the data in the param, and inserts it into the BST. It also increments the size variable by one
// it takes the BST pointer, and an integer to insert. It will return zero upon success and one upon failure
// O(log(n))
int insertBST(BST * tree, int data) {

    Node * newNode = createNode(data);

    if(newNode) {
        BSTInsert(newNode, tree->root);
        tree->size++;
        return 0;
        
    }
    else {
        return 1;
    }

}

// this function just returns the size of the BST stored in the BST overhead struct
// it takes a BST pointer as its param
// O(1)
int getSizeBST(BST * tree) {

    return tree->size;

}

// this function returns the value of the smallest integer in the BST
// it takes a BST pointer as its param
// O(log(n))
int getMinBST(BST * tree) {

    Node * p;
    for(p = tree->root; p->left != NULL; p = p->left) {

    }
    return p->data;

}

// this function calls the descending order function to print the integers in the BST in post order (i believe in this case post order would mean the same as descending order)
// it takes a BST pointer as its param
// O(n)
void postOrderPrintBST(BST * tree) {

    descendingOrderPrintBST(tree->root);

}

//this function freee all the nodes in the BST and the BST pointer itself
// it takes a BST pointer as its param
// O(n)
void freeBST(BST * tree) {

    freeTree(tree->root);

    free(tree);

}
