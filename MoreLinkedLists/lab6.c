#include <stdlib.h>
#include <stdio.h>
#include "lab6.h"

// Helper Function
Node * createNode(void * data) {

    Node *p;
    p = malloc(sizeof(Node));
    if (p) {
        p->data = data;
        p->next = NULL;
    }
    return(p);

}

//This function will initialize the provided pointer to Node * to an empty list. It will return 0 if
//initialization was successful, or 1 if it was not.
int makeList(Node **list) {

    Node * p;
    p = malloc(sizeof(Node)); // mallocs a dummy node with no content
    if(p) {
        p->next = NULL; // p->next will be null because it is an empty list
        *list = p; // points the users pointer to the dummy node
        return 0;// returns 0 to indicate success
    }
    else {
        return 1; // returns 1 to indicate failure
    }

}

// This function takes a list, and returns the number of elements on the list. 
int getSize(Node *list) {

    Node * p;
    int count = 0; // variable to keep track of the length
    for(p = list->next; p != NULL; p = p->next) { // loops through the list
        count++; // increments count
    }
    return count; // returns list length


}

// This function takes a list, and returns the element at the given index, or NULL if the index is
// invalid.
void * getAtIndex(Node *list, int index) {

    if ((index > 0) && (index <= getSize(list))) { // checks to make sure the index is valid
        Node * p;
        int count; // variable to keep track of where we are on the list
        p = list->next; // p will point to the first element in the list not the dummy node
        for (count = 1; count < index; count++) { // loops index number of times
            p = p->next; // moves the p pointer through the list
        }   
        return p->data; // returns the data from the node at the given index
    }
    else {
        return NULL; // if the index was invalid we return NULL
    }

}

// This function takes a pointer to Node, and inserts the given data at the tail of the list. It returns
// 0 if insertion was successful, or 1 if insertion failed.
int insertAtTail(Node *list, void *data) {
    
    Node * newNode; // helpful node pointer

    if(list->next) { // if the list isn't empty
        Node * p; 
        p = list->next; 
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
    else { // if the list is empty
        newNode = createNode(data);
        if(newNode) {
        list->next = newNode; // sets the newnode directly after the dummmy node
            return 0; // returns 0 to indicate success
        }
        else {
            return 1; // returns 1 to indicate failure
        } 
    }



}

//This function takes a pointer to Node, and removes the element at the head of the list (if any). It
//will return the data which was removed from the list, or NULL if the list was empty. 
void * removeFromHead(Node *list) {

    if(list->next) { // checks to make sure the list isn't empty
        Node * p = list->next; // creates our p pointer and sets it equal to the pointer to the first element
        list->next = p->next; // moves the list pointer to the next node
        void * rmData = p->data; // stores the removed data
        free(p);// frees the memory allocated to the removed node
        return rmData; // returns the data from the removed node
        
       
    }
    else {
        return NULL; // returns Null if the list was empty
    }

}

//This function takes a pointer to Node *, and frees the memory allocated to the list. After freeing,
// it sets the pointer to NULL. this frees the dummy node as well.
void freeList(Node **list) {
    Node * p = *list; // creates our p pointer and sets it equal to the list pointer
    Node * temp; // this pointer will help us free the memory with out potential errors
    while(p != NULL) {
        temp = p;
        p = p->next; // moves the p pointer through the list
        free(temp); // frees the temp pointer after p has already moved on
    }
    *list = NULL;

}