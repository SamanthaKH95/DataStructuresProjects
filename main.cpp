//
//  main.cpp
//  160_Project0
//
//  Created by Samantha Ho on 9/2/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[])

{
    string fileName;
    ifstream inFile;
    
    int numOfAdditions;
    int numOfDeletions;
    int addNum;
    int removeNum;
    string stuffToIgnore;
    string lineOfAdditions;
    string lineOfDeletions;
    LL linkedlist;
    
    fileName = string(argv[1]); //converting filename from cmd line arg
    inFile.open(fileName.c_str());
    
    inFile >> numOfAdditions;
    getline(inFile, stuffToIgnore);
    
    /*
    cout << "There are " << numOfAdditions << " integers to add." << endl;
    cout << "Adding them onto linked list now..." << endl;
    */
    
    inFile >> addNum;
    linkedlist.addFirst(addNum); 
    
    /*
    while (inFile.peek() != '\n' && inFile )
    {
        inFile >> addNum;
        cout << addNum << " ";
        linkedlist.add(addNum);
    }
     
     */
    
    getline(inFile, lineOfAdditions);
    istringstream in(lineOfAdditions);
    while (in >> addNum)
    {
        //cout << addNum << " ";
        linkedlist.add(addNum);
    }
    
    
    /*
    cout << endl << endl << "Here is the linked list after first " <<numOfAdditions << " additions"
    << endl << endl; */
    linkedlist.print();
    
    cout << endl << endl << endl;
    
    inFile >> numOfDeletions;
    getline(inFile, stuffToIgnore);
    
    /*
    cout << endl << "There are " << numOfDeletions << " integers to delete." << endl;
    cout << endl << "Deleting from linked list now..." << endl << endl;
    
    cout << endl << "Values to be deleted: " << endl;
    */
    getline(inFile, lineOfDeletions);
    istringstream inn (lineOfDeletions);
    while (inn >> removeNum)
    {
        //cout << removeNum << " ";
        linkedlist.remove(removeNum);
    }
    
    
    //cout << endl << endl << "Here is the final linked list after additions and deletions" << endl;
    linkedlist.print();
    
    cout << endl; 
    
    inFile.close();
    
    return 0;
}
