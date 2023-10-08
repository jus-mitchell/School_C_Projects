#include "lab7.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

// node struct
struct Node {
    void * data;
    Node * next;
};

// info struct (contains the pointer to the head of the list)
struct Info {
    Node * head;
    int size;
};

// Helper Function O(1)
// creates a new node
Node * createNode(void * data) {

    Node *p;
    p = malloc(sizeof(Node));
    if(p) {

        p->data = data;
        p->next = NULL;
    }
    return(p);

}

// Helper Function O(1)
// inserts an item at the head of a simple linked list
int insertAtHead(Info * info, void * data) {

    if(info->head) {
        Node * p = createNode(data);
        if(p) {
            p->next = info->head;
            info->head = p;
            (info->size)++;
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        Node * p = createNode(data);
        if(p) {
            info->head = p;
            (info->size)++;
            return 0;
        }
        else {
            return 1;
        }
    }

}

// Helper Function O(1)
// removes an item  from the head of a simple linked list
void * removefromHead(Info * info) {

    if(info->head) {
        void * rmData = info->head->data;
        Node * p = info->head;
        info->head = info->head->next;
        (info->size)--;
        free(p);
        return rmData;
    }
    else {
        return NULL;
    }

}

// O(1)
// this function initiates a stack and returns it
Stack initStack() { 

    Stack s; // declares a stack struct
    s.info = malloc(sizeof(Info)); // mallocs the memory required for the info struct
    if(s.info) { // initializes the info struct members
        s.info->head = NULL;
        s.info->size = 0;
    }
    else {
        s.info = NULL; // if malloc fails info will become NULL
    }
    return s;

}

// O(1)
// this function returns the size of the stack stored in the info struct
int getSize(Stack s) {

    return s.info->size; 


}

// O(1)
// this function returns data from the node on top of the stack
void * peekStack(Stack s) {

    return s.info->head->data;

}

// O(1)
// this function pushes a node onto the stack. it returns an error code
int pushStack(Stack s, void *data) {

    int ec = insertAtHead(s.info, data); // inserts a node at the head of a list and increments the size by one, returns the error code

    return ec; 

}

// O(1)
// this function pops a node from the stack. it returns the data form the removed node
void * popStack(Stack s) {

    return removefromHead(s.info); // removes a node from the head of a list returns its data

}

// O(n)
// this function checks to see if a certain item is contained in the stack. returns 0 if not and 1 if yes
int stackContains(Stack s, void *data) {

    Node * p; 
    int contains = 0;
    for(p = s.info->head; p != NULL; p = p->next) { 
        if(p->data == data) {
            contains = 1; // if the data item is found contains becomes true
        }
    } 
    return contains;

}

// O(n)
// this function frees all the memory allocated to the stack
void freeStack(Stack s) {

    Node * p = s.info->head; // points p to the head of the stack
    Node * temp;
    while(p) {
        temp = p; // temp is pointed to the current stack position
        p = p->next; // moves through stack
        free(temp); // frees the memory
    }
    free(s.info); // frees the stack info struct

}