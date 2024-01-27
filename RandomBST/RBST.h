#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;

struct Node {

    Node * left, * right;
    int key, treeSize;

};

typedef struct RandomBinarySearchTree {

    Node * root;

} RBST;

// RBST Functions

RBST initRBST(void);

int insertRBST(RBST, int key);

int freeRBST(RBST);

int testInsertRBST(int n, int * testValues);

int testFreeRBST(int n, int * testValues);

int scalingTest(int n);

// Helper Functions

int genRandIndex(int low, int high);

Node * createNode(int key);

Node * insertNode(Node* root, int key);

int flattenTree(Node * tree, int * array, int index);

Node * buildTree(Node * root, int* array, int first, int last);

Node * rebuildTree(Node * tree, Node * newNode, int *count);

Node * insertRandBST(Node * tree, Node * newNode, int * count);

void freeTree(Node * tree, int * count);