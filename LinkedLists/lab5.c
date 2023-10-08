#include <stdlib.h>
#include <stdio.h>
#include "lab5.h"

// helper function prototype
Node * createNode(void * data);

// this function inits a empty list pointer by setting it to Null
// it takes the address of a Node pointer as its parameter
// it returns 0 always
int makeList(Node **list) {

    *list = NULL;
    return 0;

}

// this function returns the size of a list
// it takes a Node pointer as its parameter
int getSize(Node *list) {

    Node * p; // a pointer we can work with
    int length = 0; // variable to keep track of the length
    for(p = list; p != NULL; p = p->next) { // loops through the list
        length++; // increments length
    }
    return length; // returns list length

}

// this function creates a new node and appends it at the end of the list
// it takes the address of a node pointer and a pointer to the data that needs to need inserted as its parameters
// it returns 0 upon successful allocation and asssignment
int insertAtTail(Node **list, void *data) {

    Node * newNode; // helpful node pointer

    if(*list) { // if the list isn't empty
        Node * p; 
        p = (*list); 
        while (p->next != NULL) { // moves p to the last node
            p = p->next;
        }
        newNode = createNode(data); // creates a new node
        if(newNode) {
            p->next = newNode; // if the node was created successful it is appended at the end
            return 0; // returns 0 to indicate success
        }
        else  {
            return 1; // returns 1 to indicate failure
        }
    }
    else { // this only applys if the list was passed in as an empty list
        newNode = createNode(data);
        if(newNode) {
            *list = newNode; // sets the empty list equal to the new node
            return 0;
        }
        else {
            return 1;
        } 
    }

}

// this function removes a node from the head of a list
// it takes the address of a node pointer as its parameter
// it returns the data from the removed node
void * removeFromHead(Node **list) {

    if(*list) { // checks to make sure the list isn't empty
        Node * p = *list; // creates are p pointer and sets it equal to the list pointer
        *list = p->next; // moves the list pointer to the next node
        free(p); // frees the memory allocated to the removed node
        return p->data; // returns the data from the removed node
    }
    else {
        return NULL; // returns Null if the list was empty
    }

}

// this function frees all nodes in a list
// takes the address of a Node pointer as its parameter
void freeList(Node **list) {

    Node * p = *list; // creates are p pointer and sets it equal to the list pointer
    Node * temp; // this pointer will help us free the memory with out potential errors
    while(p != NULL) {
        temp = p;
        p = p->next; // moves the p pointer through the list
        free(temp); // frees the temp pointer after p has already moved on
    }
    *list = NULL;

}

// this is a helper function it merely creates a new node with data provided by the user
Node * createNode(void * data) {

    Node *p;
    p = malloc(sizeof(Node));
    if (p) {
        p->data = data;
        p->next = NULL;
    }
    return(p);

}