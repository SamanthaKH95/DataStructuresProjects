//
//  LL.h
//  P2
//
//  Created by Samantha Ho on 10/9/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef LL_h
#define LL_h


class Node
{
public:
    int info; //info member
    Node *rightChild; //pointer to next node
    Node *leftChild;
    Node(int num = 0, Node *rightPtr = NULL, Node *leftPtr = NULL) {info = num, rightChild = rightPtr, leftChild = leftPtr;} //in-line constructor
    
    //in-line constructor
    
}; //END definition templatized class Node

struct node
{
    int data;
    node* right=NULL;
    node* left=NULL; //initialized to null to safeguard
    int height;
    
    node(int data = 0, node *rightptr = NULL, node *leftptr = NULL, int height = 0)
    {
        this->data = data;
        this->right = rightptr;
        this->left = leftptr;
        this->height = height; 
    }
};

struct TreeNode
{
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode()
    {
        this -> key = 0;
        this -> parent = NULL;
        this -> left = NULL;
        this -> right = NULL;
    }
    
    TreeNode(int x)
    {
        this -> key = x;
        this -> parent = NULL;
        this -> left = NULL;
        this -> right = NULL;
    }
};

#endif /* LL_hpp */
