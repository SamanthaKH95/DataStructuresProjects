//
//  Tree.h
//  P2
//
//  Created by Samantha Ho on 10/24/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <algorithm>

//contains code for BST, AVLTree, and Splay Tree

class BST
{
public:
    Node* Root= NULL; //initialize to null for safekeeping
    int comparisons;
    
    bool publicSearch(int num);
    bool privateSearch(int num, Node * &t);
    
    
    void publicInsert(int num);
    void Privateinsert(int num, Node * &t);
    
    void publicRemove(int num);
    void privateRemove(int num, Node * &t);
    
    void printTree(Node* root, string& str); //display printing to console

    Node* findMin (Node *t) const;
    
    ~BST(); //deallocate tree, calls makeEmpty to help out
    void makeEmpty(Node *root);
    
    BST(); //default constructor, constructs only the root and comparisons
    BST(Node* rootPtr, int numcomparisons); //parameter constructor, theoretically not used
    
};

class AVLTree
{

public:
    node* root=NULL;
    int comparisons;
    
    bool publicSearch(int num);
    bool privateSearch(int num, node *t );
    
    void publicInsert(int num);
    void privateInsert(int num, node* &t);
    
    void publicRemove(int num);
    void privateRemove(int num, node * &t);

    
    void rotateWithLeftChild(node* &k2);
    void doubleWithLeftChild(node* &k3);
    void rotateWithRightChild(node* &k1);
    void doubleWithRightChild(node* &k1);

    
    void printTree(node *root, string& str);

    void makeEmpty(node *t);
    ~AVLTree(); //deallocate tree by postordertraversal
    
    AVLTree(); //default constructor, constructs only the root and comparisons
    AVLTree(node* rootPtr, int numcomparisons); //parameter constructor
    
    void balance(node* &t);
    
    int height(node* t);
    node* findMin(node* t);
    
    
    
};

class SplayTree
{
public:
    TreeNode *root;
    TreeNode *nullNode = NULL;
    int comparisons;
    
    SplayTree();
    ~SplayTree();
    const int & findMin();
    const int & findMax();
    bool contains( const int & x ); //search
    void makeEmpty();
    bool isEmpty() const;

    //void insert(const int & x);
    //void remove(const int & x);
    
    void rotateWithLeftChild(TreeNode * & k2 );
    void rotateWithRightChild(TreeNode * & k1 );
    
    //void splay(const int & x, TreeNode * & t );
    
    
    
    
    void zig(TreeNode*);
    void zig_zig(TreeNode*);
    void zig_zag(TreeNode*);
    SplayTree(TreeNode* x);
    TreeNode* search(int x);
    void splay(TreeNode* x);
    void insert(int x);
    void remove(int x);
    TreeNode* subtree_max(TreeNode *subRoot);
    TreeNode* subtree_min(TreeNode *subRoot);
    void makeEmpty(TreeNode *t);
    
    void printTree(TreeNode *root, string& str);
    
    
    
    
    
    
    
    
    


    
    
};

/* ////////////////////////////////////////
 //////////////////////////////////////////
 BST Implementation
 ////////////////////////////////////////*/

BST::~BST()
{
    //first deallocate entire tree by traversal and deletion then make Root null
    if (Root == NULL)
    {
        comparisons++;
        // don't do anything
    }
    else
    {
        makeEmpty(Root);
    }
    //make Root null just to be safe
    Root = NULL;
    
}

void BST::makeEmpty(Node *root)
{
    if (root == NULL)
    {
        comparisons++;
        return; 
    }
    
    makeEmpty(root->leftChild);
    makeEmpty(root->rightChild);
    delete root;
}

BST::BST()
{
    Root = NULL;
    comparisons = 0;
}

BST::BST(Node* rootPtr, int numcomparisons)
{
    Root = rootPtr;
    comparisons = numcomparisons;
}

bool BST::publicSearch(int num)
{
    return privateSearch(num, Root);
}
bool BST::privateSearch(int num, Node * &t)
{
    if (t == NULL)
    {
        comparisons++;
        return false;
    }
    else if (num < t->info)
    {
        comparisons++;
        return privateSearch(num, t->leftChild);
    }
    
    else if (t->info < num)
    {
        comparisons++;
        return privateSearch(num, t->rightChild);
    }
    
    
    else
    {
        comparisons++;
        return true; //Match!
    }
    
}




void BST::publicRemove(int num)
{
    privateRemove(num, Root);
}

void BST::privateRemove(int num, Node * &t)
{
    
    if (t == NULL)
    {
        comparisons++;
        return; //item not found, do nothing
    }
    if (num < t->info)
    {
        comparisons++;
        privateRemove(num, t->leftChild);
    }
    else if (t->info < num)
    {
        comparisons++;
        privateRemove(num, t->rightChild);
    }
    else if (t->leftChild != NULL && t->rightChild != NULL)//two children
    {
        comparisons++;
        t->info = findMin(t->rightChild)->info;
        privateRemove(t->info, t->rightChild);
    }
    else
    {
        comparisons++;
        Node *oldNode = t;
        t = (t->leftChild != NULL) ? t->leftChild : t->rightChild;
        delete oldNode;
    }
}

Node* BST::findMin (Node *t) const
{
    if (t == NULL)
    {
        return NULL;
    }
    
    
    if (t->leftChild == NULL)
        return t;
    return findMin(t->leftChild);
}


void BST::publicInsert(int num)
{
    Privateinsert(num, Root);
}

void BST::Privateinsert(int num, Node * &t)
{
    if (t == NULL)
    {
        comparisons++;
        t = new Node (num, NULL, NULL);
    }
    else if (num < t->info)
    {
        comparisons++;
        Privateinsert(num, t->leftChild);
    }
    else if (t->info < num)
    {
        comparisons++;
         Privateinsert(num, t->rightChild);
    }
    else
        return;
}


void BST::printTree(Node* root, string& str)
{
    if (root == NULL)
    {
        comparisons++; //does this belong here?
        return;
    }
    //cout << '[';
    // push the root data as character
    str.push_back('[');
    cout << (root->info);
    
    //write print method
    
    
    // if leaf node, then return
    if (!root->leftChild && !root->rightChild)
        return;
    
    // for left subtree
    cout<< '[';
    printTree(root->leftChild, str);
    cout<<']';
    
    // only if right child is present to
    // avoid extra parenthesis
    if (root->rightChild)
    {
        cout<< '[';
        printTree(root->rightChild, str);
        cout<<']';
    }
    
    
}



/* ////////////////////////////////////////
 //////////////////////////////////////////
 AVL Implementation
 ////////////////////////////////////////*/

AVLTree::AVLTree()
{
    root = NULL;
    comparisons = 0;
    
}

int AVLTree::height(node* t)
{
    comparisons++;
    return t == NULL ? -1 : t->height;
}

node* AVLTree::findMin(node* t)
{
    if(t == NULL)
    {
        comparisons++;
        return NULL;
    }
    
    else if(t->left == NULL)
    {
        comparisons++;
        return t;
    }
    
    else
    {
        comparisons++;
        return findMin(t->left);
    }
    
}


void AVLTree::publicInsert(int num)
{
    privateInsert(num, root);
}

void AVLTree::privateInsert(int num, node* &t)
{
    if (t==NULL)
    {
        comparisons++;
        t = new node (num, NULL, NULL, 0); //beware, may have something wrong with node constructor
    }
    else if (num < t->data)
    {
        comparisons++;
        privateInsert(num, t->left);
    }
    else if (t->data < num)
    {
        comparisons++;
        privateInsert(num, t->right);
    }
    
        balance(t);
}

void AVLTree::balance(node* &t)
{
    //update height here
    t->height = std::max(height(t->left), height(t->right)) + 1;

    if (t==NULL)
    {
        comparisons++;
        return;
    }
    
    if (height(t->left) - height(t->right) >1)
    {
        comparisons++;
        if (height(t->left->left) >= height(t->left->right))
        {
            comparisons++;
            rotateWithLeftChild(t);
        }
        else
        {
            comparisons++;
            doubleWithLeftChild(t);
        }
    }
    else
    {

        if(height(t->right) - height(t->left) >1)
        {
            comparisons++;
            if(height(t->right->right) >= height(t->right->left))
            {
                comparisons++;
                rotateWithRightChild(t);
            }
            else
            {
                comparisons++;
                doubleWithRightChild(t);
            }
        }
    }
    
}

void AVLTree::rotateWithLeftChild(node* &k2)
{
    node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right))+1;
    comparisons++;
    k1->height = max(height(k1->left), k2->height)+1;
    comparisons++;
    k2=k1;
}
void AVLTree::doubleWithLeftChild(node* &k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AVLTree::rotateWithRightChild(node* &k1)
{
    node *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    comparisons++;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    comparisons++;
    k1 = k2;
}
void AVLTree::doubleWithRightChild(node* &k1)
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}



bool AVLTree::publicSearch(int num)
{
    return privateSearch(num, root);
}

bool AVLTree::privateSearch(int num, node *t )
{
    if( t == nullptr )
    {
        comparisons++;
        return false;
    }
    
    else if( num < t->data )
    {
        comparisons++;
        return privateSearch( num, t->left );
    }
    
    else if( t->data < num )
    {
        comparisons++;
        return privateSearch( num, t->right );
    }
    
    else
    {
        comparisons++;
        return true;    // Match
    }
    
}


void AVLTree::publicRemove(int num)
{
    privateRemove(num, root);
}
void AVLTree::privateRemove(int num, node * &t)
{
    if(t==NULL)
    {
        comparisons++;
        return; //item not found, do nothing
    }
    if(num < t->data)
    {
        comparisons++;
        privateRemove(num, t->left);
    }
    else if(t->data < num)
    {
        comparisons++;
        privateRemove(num, t->right);
    }
    else if(t->left != NULL && t->right !=NULL) //two children
    {
        comparisons++;
        t->data = findMin(t->right)->data;
        privateRemove(t->data, t->right);
    }
    else
    {
        comparisons++;
        node *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}

AVLTree::~AVLTree()
{
    //first deallocate entire tree by traversal and deletion then make Root null
    if (root == NULL)
    {
        comparisons++;
        // don't do anything
    }
    else
    {
        makeEmpty(root);
    }
    //make Root null just to be safe
    root = NULL;
}

void AVLTree::makeEmpty(node *t)
{
    if(t == NULL)
    {
        comparisons++;
        return;
    }
    
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}


AVLTree::AVLTree(node* rootPtr, int numcomparisons)
{
    
    root = rootPtr;
    comparisons = numcomparisons;
}

void AVLTree::printTree(node *root, string& str)
{
    if (root == NULL)
    {
        comparisons++; //does this belong here?
        return;
    }
    
    // push the root data as character
    cout<< (root->data);
    //print method
    
    //write print method
    
    // if leaf node, then return
    if (!root->left && !root->right)
        return;
    
    // for left subtree
    cout <<'[';
    printTree(root->left, str);
    cout <<']';
    
    // only if right child is present to
    // avoid extra parenthesis
    if (root->right)
    {
        cout <<'[';
        printTree(root->right, str);
        cout <<']';
    }
    
}


/* ////////////////////////////////////////
 //////////////////////////////////////////
 SPLAY Implementation
 ////////////////////////////////////////*/

void SplayTree::zig(TreeNode* x)
{
    TreeNode *p = x -> parent;
    if (p -> left == x)
    {
        comparisons++;
        TreeNode *A = x -> left;
        TreeNode *B = x -> right;
        TreeNode *C = p -> right;
        
        x -> parent = NULL;
        x -> right = p;
        
        p -> parent = x;
        p -> left = B;
        
        if (B != NULL) B -> parent = p;
    }
    else
    {
        comparisons++;
        TreeNode *A = p -> left;
        TreeNode *B = x -> left;
        TreeNode *C = x -> right;
        
        x -> parent = NULL;
        x -> left = p;
        
        p -> parent = x;
        p -> right = B;
        
        if (B != NULL) B -> parent = p;
    }
}


void SplayTree::zig_zig(TreeNode* x)
{
    TreeNode *p = x -> parent;
    TreeNode *g = p -> parent;
    if (p -> left == x)
    {
        comparisons++;
        TreeNode *A = x -> left;
        TreeNode *B = x -> right;
        TreeNode *C = p -> right;
        TreeNode *D = g -> right;
        
        x -> parent = g -> parent;
        x -> right = p;
        
        p -> parent = x;
        p -> left = B;
        p -> right = g;
        
        g -> parent = p;
        g -> left = C;
        
        
        if (x -> parent != NULL)
        {
            comparisons++;
            comparisons++;
            if (x -> parent -> left == g) x -> parent -> left = x;
            else x -> parent -> right = x;
        }
        
        if (B != NULL) B -> parent = p;
        comparisons++;
        
        if (C != NULL) C -> parent = g;
        comparisons++;
    }
    else
    {
        TreeNode *A = g -> left;
        TreeNode *B = p -> left;
        TreeNode *C = x -> left;
        TreeNode *D = x -> right;
        
        x -> parent = g -> parent;
        x -> left = p;
        
        p -> parent = x;
        p -> left = g;
        p -> right = C;
        
        g -> parent = p;
        g -> right = B;
        
        if (x -> parent != NULL)
        {
            comparisons++; comparisons++;
            if (x -> parent -> left == g) x -> parent -> left = x;
            else x -> parent -> right = x;
        }
        
        if (B != NULL) B -> parent = g;
        comparisons++;
        if (C != NULL) C -> parent = p;
        comparisons++;
    }
}

void SplayTree::zig_zag(TreeNode* x)
{
    TreeNode *p = x -> parent;
    TreeNode *g = p -> parent;
    if (p -> right == x)
    {
        comparisons++;
        TreeNode *A = p -> left;
        TreeNode *B = x -> left;
        TreeNode *C = x -> right;
        TreeNode *D = g -> right;
        
        x -> parent = g -> parent;
        x -> left = p;
        x -> right = g;
        
        p -> parent = x;
        p -> right = B;
        
        g -> parent = x;
        g -> left = C;
        
        if (x -> parent != NULL)
        {
            comparisons++;
            if (x -> parent -> left == g) x -> parent -> left = x;
            else x -> parent -> right = x;
        }
        
        if (B != NULL) B -> parent = p;
        comparisons++;
        
        if (C != NULL) C -> parent = g;
        comparisons++;
    }
    else
    {
        comparisons++;
        TreeNode *A = g -> left;
        TreeNode *B = x -> left;
        TreeNode *C = x -> right;
        TreeNode *D = p -> right;
        
        x -> parent = g -> parent;
        x -> left = g;
        x -> right = p;
        
        p -> parent = x;
        p -> left = C;
        
        g -> parent = x;
        g -> right = B;
        
        if (x -> parent != NULL)
        {
            comparisons++;
            if (x -> parent -> left == g) x -> parent -> left = x;
            else x -> parent -> right = x;
        }
        
        if (B != NULL) B -> parent = g;
        comparisons++;
        
        if (C != NULL) C -> parent = p;
        comparisons++;
    }
}

void SplayTree::splay(TreeNode* x)
{
    while (x -> parent != NULL)
    {
        comparisons++;
        TreeNode *p = x -> parent;
        TreeNode *g = p -> parent;
        if (g == NULL) zig(x);
        else if (g -> left == p && p -> left == x) zig_zig(x);
        else if (g -> right == p && p -> right == x) zig_zig(x);
        else zig_zag(x);
    }
    this -> root = x;
}


SplayTree::SplayTree()
{
    root = NULL;
    comparisons = 0;
}

SplayTree::SplayTree(TreeNode* x)
{
    this -> root = x;
    comparisons = 0;
}

TreeNode* SplayTree::search(int x)
{
    TreeNode *ret = NULL;
    TreeNode *curr = this -> root;
    TreeNode *prev = NULL;
    while (curr != NULL)
    {
        comparisons++;
        prev = curr;
        if (x < curr -> key) curr = curr -> left;
        else if (x > curr -> key) curr = curr -> right;
        else
        {
            ret = curr;
            break;
        }
    }
    if (ret != NULL) splay(ret);
    else if (prev != NULL) splay(prev);
    return ret;
}

void SplayTree::insert(int x)
{
    if (root == NULL)
    {
        comparisons++;
        root = new TreeNode(x);
        return;
    }
    TreeNode *curr = this -> root;
    while (curr != NULL)
    {
        comparisons++;
        if (x < curr -> key)
        {
            comparisons++;
            if (curr -> left == NULL)
            {
                comparisons++;
                TreeNode *newNode = new TreeNode(x);
                curr -> left = newNode;
                newNode -> parent = curr;
                splay(newNode);
                return;
            }
            else curr = curr -> left;
            
        }
        else if (x > curr -> key)
        {
            comparisons++;
            if (curr -> right == NULL)
            {
                comparisons++;
                TreeNode *newNode = new TreeNode(x);
                curr -> right = newNode;
                newNode -> parent = curr;
                splay(newNode);
                return;
            }
            else curr = curr -> right;
        }
        else
        {
            splay(curr);
            return;
        }
    }
}

void SplayTree::remove(int x)
{
    TreeNode *del = search(x);
    if (del == NULL)
    {
        comparisons++;
        return;
    }
    TreeNode *L = del -> left;
    TreeNode *R = del -> right;
    if (L == NULL && R == NULL)
    {
        comparisons++;
        this -> root = NULL;
        
    }
    else if (L == NULL)
    {
        comparisons++;
        TreeNode *M = subtree_min(R);
        splay(M);
    }
    else if (R == NULL)
    {
        comparisons++;
        TreeNode *M = subtree_max(L);
        splay(M);
    }
    else
    {
        comparisons++;
        TreeNode *M = subtree_max(L);
        splay(M);
        M -> right = R;
        R -> parent = M;
    }
    delete del;
}

TreeNode* SplayTree::subtree_max(TreeNode *subRoot)
{
    TreeNode *curr = subRoot;
    while (curr -> right != NULL) curr = curr -> right;
    return curr;
}

TreeNode* SplayTree::subtree_min(TreeNode *subRoot)
{
    TreeNode *curr = subRoot;
    while (curr -> left != NULL) curr = curr -> left;
    return curr;
}

void SplayTree::makeEmpty(TreeNode *t)
{
    //might be dangerous if parent pointer is not dealt with...
    
    if(t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

SplayTree::~SplayTree()
{
    //deallocating memory for whole tree
    if (root == NULL)
    {
        comparisons++;
        //don't do anything
    }
    else
    {
        makeEmpty(root);
    }
    //make Root null just to be safe
    root = NULL;
    
}


 
 //recursive ones are n^2s


void SplayTree::printTree(TreeNode *root, string& str)
{
    if (root == NULL)
    {
        comparisons++; //does this belong here?
        return;
    }
    
    // push the root data as character
    cout<< (root->key);
    //print method
    
    //write print method
    
    // if leaf node, then return
    if (!root->left && !root->right)
        return;
    
    // for left subtree
    cout <<'[';
    printTree(root->left, str);
    cout <<']';
    
    // only if right child is present to
    // avoid extra parenthesis
    if (root->right)
    {
        cout <<'[';
        printTree(root->right, str);
        cout <<']';
    }
    
    //print function
}




 
 





#endif /* Tree_h */
