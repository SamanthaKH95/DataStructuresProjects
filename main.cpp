//
//  main.cpp
//  P2
//
//  Created by Samantha Ho on 10/9/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[])
{

    string fileName;
    ifstream inFile;
    
    string dollarSign;
    string addNum;
    string searchNum;
    string removeNum;
    string stuffToIgnore;
    string lineOfSearches;
    string lineOfAdditions;
    string lineOfDeletions;
    
    string str = "";
    
    /* -------------------------BST File Opening----------------------------------*/
    
    BST binarySearchTree;
    
    fileName = string(argv[1]); //converting filename from cmd line arg
    inFile.open(fileName.c_str());
    
    
    //getting the entire line of initial list into lineOfAdditions and parcing
    getline(inFile, lineOfAdditions);
    istringstream in(lineOfAdditions);
    while (in >> addNum)
    {
        //cout << addNum << " ";
        int addNum2 = stoi(addNum);
        binarySearchTree.publicInsert(addNum2);
    }
    
    //perhaps being replaced by ascii values????
    
    
    //outputting after all insertions
    str = "";
    cout << "this is the BST after insertion:";
    cout << '[';
    binarySearchTree.printTree(binarySearchTree.Root, str);
    cout << endl;
    
    
    
    
    
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfSearches);
    istringstream inn (lineOfSearches);
    
    
     while (inn >> searchNum)
     {
     bool found;
     //cout << searchNum << " ";
     int searchNum2 = stoi(searchNum);
     found = binarySearchTree.publicSearch(searchNum2);
     }
     
     
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfDeletions);
    istringstream innn (lineOfDeletions);
    
    
    
    while (innn >> removeNum)
    {
        //cout << removeNum << " ";
        int removeNum2 = stoi(removeNum);
        binarySearchTree.publicRemove(removeNum2);
    }
   
    //outputting after all removals
    str = "";
    cout << "This is the BST after removals: [";
    binarySearchTree.printTree(binarySearchTree.Root, str);
    cout << "[" << str << "]" << endl;
    
    
     
    cout << "BST Comparisons: " << binarySearchTree.comparisons << endl; 
    
    inFile.close();
    /* -------------------------BST File Closing----------------------------------*/
    
    
   
    
    
    
    /* -------------------------AVL File Opening----------------------------------*/
    
    AVLTree avltree;
    
    fileName = string(argv[1]); //converting filename from cmd line arg
    inFile.open(fileName.c_str());
    
    
    //getting the entire line of initial list into lineOfAdditions and parcing
    getline(inFile, lineOfAdditions);
    istringstream in2(lineOfAdditions);
    while (in2 >> addNum)
    {
        //cout << addNum << " ";
        int addNum2 = stoi(addNum);
        avltree.publicInsert(addNum2);
    }
    
    
    //outputting after all insertions
    str = "";
    cout << "This is the AVL tree after insertions:[";
    avltree.printTree(avltree.root, str);
    cout << "[" << str << "]" << endl;
    
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfSearches);
    istringstream inn2 (lineOfSearches);
    
    while (inn2 >> searchNum)
    {
        //cout << searchNum << " ";
        int searchNum2 = stoi(searchNum);
        avltree.publicInsert(searchNum2);
        
    }
    
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfDeletions);
    istringstream innn2 (lineOfDeletions);
    
    while (innn2 >> removeNum)
    {
        //cout << removeNum << " ";
        int removeNum2 = stoi(removeNum);
        avltree.publicRemove(removeNum2);
        
    }
    
    //outputting after all removals
    str = "";
    cout << "This is the AVL tree after removals: [";
    avltree.printTree(avltree.root, str);
    cout << "[" << str << "]" << endl;

    
    cout << "AVL Comparisons: " << avltree.comparisons << endl;
    inFile.close();
    
    /* -------------------------AVL File Closing----------------------------------*/
    
    
    
    
    
    
    
    /* -------------------------Splay File Opening----------------------------------*/
    
    
    SplayTree splaytree;
    
    fileName = string(argv[1]); //converting filename from cmd line arg
    inFile.open(fileName.c_str());
    
    
    //getting the entire line of initial list into lineOfAdditions and parcing
    getline(inFile, lineOfAdditions);
    istringstream in3(lineOfAdditions);
    while (in3 >> addNum)
    {
        //cout << addNum << " ";
        int addNum2 = stoi(addNum);
        splaytree.insert(addNum2);
    }
    
    
    
    //outputting after all insertions
    str = "";
    cout << "This is the Splay Tree after insertions: [";
    splaytree.printTree(splaytree.root, str);
    cout << "[" << str << "]" << endl;
    
     
     
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfSearches);
    istringstream inn3 (lineOfSearches);
    
    while (inn3 >> searchNum)
    {
        bool found;
        //cout << searchNum << " ";
        int searchNum2 = stoi(searchNum);
        found = splaytree.search(searchNum2);
        
    }
    
    //outputting after all searches
    str = "";
    cout << "[";
    cout << "This is the Splay Tree after searches: [";
    splaytree.printTree(splaytree.root, str);
    cout << "[" << str << "]" << endl;
    
    //getting $ and ignoring rest of line
    inFile >> dollarSign;
    getline(inFile, stuffToIgnore);
    
    getline(inFile, lineOfDeletions);
    istringstream innn3 (lineOfDeletions);
    
    while (innn3 >> removeNum)
    {
        //cout << removeNum << " ";
        int removeNum2 = stoi(removeNum);
        splaytree.remove(removeNum2);
        
    }
    
    //outputting after all removals 
    str = "";
    cout << "This is the Splay Tree after removals: [";
    splaytree.printTree(splaytree.root, str);
    cout << "[" << str << "]" << endl;
    
    
    cout << "Splay Comparisons: " << splaytree.comparisons <<endl;
    
    inFile.close();
    /* -------------------------Splay File Closing----------------------------------*/
    
    
    
    
    return 0;
}
