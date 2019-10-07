//
//  LL.h
//  P1
//
//
//  Copyright © 2019 Samantha Ho. All rights reserved.
//



#ifndef MTFLIST_H
#define MTFLIST_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//class Node declaration+implementation for singly linked list
class Node
{
public:
    int info; //info member
    Node *next; //pointer to next node
    Node(int num = 0, Node *nxtPtr = NULL) {info = num, next = nxtPtr;} //in-line constructor
    
}; //END definition 


//struct MTFlist declaration

struct MTFlist
{

    Node *header;
    Node *current;

    MTFlist();
    ~MTFlist();
    
    void addFirst(int addNum);
    void add(int addNum);
    void remove(int removeNum);
    void print();
    void MTFsearch(int searchnum); 
};

//implementation

MTFlist::MTFlist()
{
    //constructor, header/current points to nothing when list is empty
    header = NULL;
    current = NULL;
}

MTFlist::~MTFlist()
{
    // Should deallocate Node objects on the list to avoid memory mismanagement
    //then set header/current back to null
    
    current = header;
    Node *helper = current->next;
    while (current != NULL && helper != NULL)
    {
        delete current;
        current = helper;
        helper = helper->next;
    }
    
    if (helper == NULL)
    {
        delete current;
    }
    
    helper = NULL;
    current = NULL;
    header = NULL;
    
}

void MTFlist::add(int addNum)
{
    current->next = new Node (addNum, NULL);
    current = current->next;
}

void MTFlist::addFirst(int addNum)
{
    
    header = new Node (addNum, NULL); //next points to null automatically when constructed
    //current will point to the last node added at the end at the end of method
    current = header;
    
}

void MTFlist::remove(int removeNum)
{
    
    Node *nodePtr;
    Node *prevptr;
    
    //case 1: header node is removenum, no need to relink next pointer
    //case 2: header node is not removenum, need to traverse to the end, relink next pointer
    if (header->info == removeNum)
    {
        nodePtr = header;
        header = header->next;
        delete nodePtr;
    }
    
    else
    {
        nodePtr = header;
        
        while (nodePtr != NULL && nodePtr->info != removeNum)
        {
            prevptr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if (nodePtr)
        {
            prevptr->next = nodePtr->next;
            delete nodePtr;
        }
    }
    
}

void MTFlist::print()
{
    current = header;
    while (current != NULL)
    {
        cout << current->info << "  ";
        current = current->next;
    }
    
}

void MTFlist::MTFsearch(int searchnum)
{
    //a searching method should be implemented (to facilitate queries). this method should
    //reorganize the list using the move-to-front strategy
    //should only be called after list is created
    
    //two helper pointers, temp trails behind search to help re-link
    Node *temp = header;
    Node *search = header->next;
    
    //searching, list traversal
    while (search != NULL)
    {
        if (search->info == searchnum)
        {
            temp->next = search->next;
            search->next = header;
            header = search;
            search = NULL; //break loop, search will be properly initialized next time method called
        }
        else
        {
            search = search->next;
            temp = temp->next;
        }
    }
    
    
    
}

#endif 
