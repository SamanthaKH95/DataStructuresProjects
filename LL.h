//
//  LL.hpp
//  160_Project0
//
//  Created by Samantha Ho on 9/6/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef LL_hpp
#define LL_hpp

//class Node declaration for singly linked list
class Node
{
public:
    int info; //info member
    Node *next; //pointer to next node
    Node(int num = 0, Node *nxtPtr = NULL) {info = num, next = nxtPtr;} //in-line constructor
    
}; //END definition templatized class Node


//class LL declaration

class LL
{
private:
    Node *header;
    Node *current; 
public:
    LL();
    ~LL(); 
    
    void addFirst(int addNum);
    void add(int addNum);
    void remove(int removeNum);
    void print();
};

//class LL implementation


LL::LL()
{
    //constructor, header/current points to nothing when list is empty
    header = NULL;
    current = NULL;
}

LL::~LL()
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

void LL::add(int addNum)
{
    current->next = new Node (addNum, NULL);
    current = current->next;
}

void LL::addFirst(int addNum)
{
    
    header = new Node (addNum, NULL); //next points to null automatically when constructed
    //current will point to the last node added at the end at the end of method
    current = header;
    
}

void LL::remove(int removeNum)
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

void LL::print()
{
    current = header;
    while (current != NULL)
    {
        cout << current->info << "  ";
        current = current->next;
    }
    
}



#endif /* LL_hpp */
