#include "jsmfvy.h"

// Helper functions

int genRandIndex(int low, int high) {

    int randomIndex = low + (int)(drand48() * (high - low + 1));
    return randomIndex;

}

Node * createNode(int key) {

    Node * p = malloc(sizeof(Node));
    if(p) {
        p->key = key;
        p->left = p->right = NULL;
        p->treeSize = 1;
    }
    return(p);

}

Node * insertNode(Node* root, int key) {
    if (!root) { // Base case: Tree is empty or leaf node reached
        root = createNode(key);
    } else if (key < root->key) { // Key is less than current root's key
        root->left = insertNode(root->left, key); // Insert in the left subtree
    } else if (key > root->key) { // Key is greater than current root's key
        root->right = insertNode(root->right, key); // Insert in the right subtree
    }
    // Update the size of the current node after insertion
    root->treeSize = 1 + (root->left ? root->left->treeSize : 0) + (root->right ? root->right->treeSize : 0);
    
    return root; // Return the updated root
}

int flattenTree(Node * tree, int * array, int index) {
    if(!tree){
        return index;
    }
    index = flattenTree(tree->left, array, index); // corrected the function name
    int tempIndex = index; // store the current index
    array[tempIndex] = tree->key;
    index = flattenTree(tree->right, array, index + 1); // corrected the function name
    free(tree); // free the current node after its children have been processed
    return index;
}

Node * buildTree(Node* root, int* array, int first, int last) {
    if (first > last) {
        return root;
    }

    // Randomly choose an index between first and last
    int randomIndex = genRandIndex(first, last);

    // Insert the random element into the tree
    root = insertNode(root, array[randomIndex]);

    // Recursively build the left and right subtrees from the remaining elements
    if (randomIndex != first) {
        buildTree(root, array, first, randomIndex - 1);
    }
    if (randomIndex != last) {
        buildTree(root, array, randomIndex + 1, last);
    }

    return root;
}

Node * rebuildTree(Node * tree, Node * newNode, int *count) {

    int totalSize = tree->treeSize + 1;  // Consider the size of the current tree
    int * array = malloc(totalSize * sizeof(int));
    if(!array) {
        return NULL;
    }
    
    // Flatten the existing tree into the array
    int lastIndex = flattenTree(tree, array, 0);

    // Add the newNode's key to the array
    array[lastIndex] = newNode->key;
    free(newNode); // Free the newNode, since we're only using its key now

    // Build a new tree from the keys in the array
    Node * newRoot = buildTree(NULL, array, 0, totalSize - 1);
    free(array);

    // Increment the count by the total number of nodes in the rebuilt tree
    *count += newRoot->treeSize;

    return newRoot;
}



Node * insertRandBST(Node * tree, Node * newNode, int * count) {
    
    // If the current tree (subtree) is NULL, it means we've found the spot to insert the newNode
    if(!tree) {
        (*count)++; // Increment the count for the node visited/processed
        return newNode; // Return the newNode to be set as the child of the parent node in the previous recursive call
    }
    
    (*count)++; // Increment the count for the current node visited/processed
    (tree->treeSize)++; // Increment the size of the current subtree to account for the newNode

    printf("tree size = %d\n", tree->treeSize);

    // With a probability of 1/treeSize, decide to rebuild the tree with newNode
    // The use of drand48() ensures the decision is randomized
    if(drand48() < (1.0/tree->treeSize)) {
        printf("Triggering rebuild...\n");
        return rebuildTree(tree, newNode, count); // Rebuild the current subtree and return the new root
    }

    // If the key of newNode is smaller than the key of the current tree node, 
    // then the newNode should be inserted in the left subtree
    if(newNode->key < tree->key) {
        tree->left = insertRandBST(tree->left, newNode, count);
    }
    // If the key of newNode is larger, then it should be inserted in the right subtree
    else if (newNode->key > tree->key) { 
        tree->right = insertRandBST(tree->right, newNode, count);
    }

    // Return the (potentially updated) root of the current subtree
    return tree;
}



void freeTree(Node * tree, int * count) {

    if (!tree) return;
    freeTree(tree->left, count);
    freeTree(tree->right, count);
    (*count)++;
    free(tree);

}

// End Helper Functions


// Assignment Functions

RBST initRBST(void) {

    RBST tree;  // Declare tree
    tree.root = NULL;
    return tree;  // Return the tree by value

}

int insertRBST(RBST tree, int key) {

   // Create a new node with the provided key
   Node * newNode = createNode(key);

   // Check if the newNode was successfully created
   if(!newNode) {
       return 0; // If memory allocation failed, return 0 to indicate no nodes were inserted
   }

   // Initialize a count variable to track the number of nodes visited/processed during the insertion
   int count = 0;

   // Call the insertRandBST function to insert the new node into the tree 
   // in a randomized manner, and update the count of nodes visited
   tree.root = insertRandBST(tree.root, newNode, &count);

   // Return the number of nodes visited during the insertion
   return count;

}


int freeRBST(RBST tree) {

    // Check if the root of the tree is NULL (i.e., the tree is empty)
    if(!tree.root) {
        return 0;  // If the tree is empty, return 0 to indicate no nodes were freed
    }

    // Initialize a count variable to keep track of the number of nodes freed
    int count = 0;

    // Call the freeTree function to free all nodes in the tree
    // and update the count with the number of nodes freed
    freeTree(tree.root, &count);

    // Set the root of the tree to NULL to indicate that the tree is now empty
    tree.root = NULL;

    // Return the total number of nodes that were freed
    return count;

}

// End Assignment Functions


// Assignment Test Functions

int testInsertRBST(int n, int * testKeys) {

    // Initialize a new RBST
    RBST tree = initRBST();
    
    // Variable to tally the number of nodes visited across all insertions
    int totalNodesVisited = 0;
    
    // Iterate through each key in the testKeys array
    for (int i = 0; i < n; i++) {
        // Insert the key into the tree and add the result to the tally
        totalNodesVisited += insertRBST(tree, testKeys[i]);
    }

    // Free the tree after the test
    freeRBST(tree);

    // Return the total number of nodes visited across all insertions
    return totalNodesVisited;

}


int testFreeRBST(int n, int * testKeys) {
    // Initialize a new RBST
    RBST tree = initRBST();
    
    // Insert all the keys into the RBST
    for (int i = 0; i < n; i++) {
        insertRBST(tree, testKeys[i]);
    }

    // Free the RBST and get the count of nodes visited during the free operation
    int nodesVisited = freeRBST(tree);

    return nodesVisited;
}

int scalingTest(int n) {
    // 1. Initialize an array of size n
    int *testKeys = malloc(n * sizeof(int));
    if (!testKeys) {
        printf("Memory allocation failed\n");
        return 0; // Indicate error
    }

    // 2. Populate the array with n distinct numbers
    // (For simplicity, we'll use numbers 1 to n, but you can use any non-duplicate numbers)
    for (int i = 0; i < n; i++) {
        testKeys[i] = i + 1;
    }

    // Shuffle the array for randomness 
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int temp = testKeys[j];
        testKeys[j] = testKeys[i];
        testKeys[i] = temp;
    }

    int nodesVisitedInsert = testInsertRBST(n, testKeys);
    printf("Number of nodes visited during insertion: %d\n", nodesVisitedInsert);

    int nodesVisitedFree = testFreeRBST(n, testKeys);
    printf("Number of nodes visited during freeing: %d\n", nodesVisitedFree);

    free(testKeys);

    return 1;
}

// Note: all the comments were generated by AI; the shuffle algorithm is from geek from stack overflow



