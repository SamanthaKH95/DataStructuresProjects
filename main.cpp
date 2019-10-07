//
//  main.cpp
//  P1
//
//
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[])

{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    string fileName;
    ifstream inFile;
    
    int numOfAdditions;
    int numOfQueries;
    int addNum;
    int searchNum;
    string stuffToIgnore;
    string lineOfAdditions;
    string lineOfQueries;
    MTFlist linkedlist; 
    
    fileName = string(argv[1]); //converting filename from cmd line arg
    inFile.open(fileName.c_str());
    
    //getting the number of total elements in initial list and ignoring rest of line
    inFile >> numOfAdditions;
    getline(inFile, stuffToIgnore);
    //cout << endl << "this is the number of additions: " << numOfAdditions << endl;
    

    
    //adding the first element to linked list to initialize head
    inFile >> addNum;
    linkedlist.addFirst(addNum);
    
    //getting the entire line of initial list into lineOfAdditions and parcing
    getline(inFile, lineOfAdditions);
    istringstream in(lineOfAdditions);
    while (in >> addNum)
    {
        //cout << addNum << " ";
        linkedlist.add(addNum);
    }
    
    //printing first population of each list !!!!! MUTE LATER!!!!
    //cout << endl << endl << "printing  linked list..." << endl;
    //linkedlist.print();
    cout << endl;
    
    cout << endl << endl << endl;

    
    //getting the number of queries and ignoring the rest of line
    inFile >> numOfQueries;
    getline(inFile, stuffToIgnore);
    
    //cout << endl << "this is the number of queries: " << numOfQueries << endl;
    
    
    //queries
    getline(inFile, lineOfQueries);
    istringstream inn (lineOfQueries);
    
    start = std::chrono::system_clock::now();
    while (inn >> searchNum)
    {
        //cout << searchNum << " ";
        linkedlist.MTFsearch(searchNum);
        
    }
    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end - start;
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    //cout << "finished computation at " << std::ctime(&end_time)
    cout<< "Time for MTFlist: " << elapsed_seconds.count() << "s\n";
    cout << endl;
    
    /*
    cout << "printing linked list after mtf search.." << endl;
    linkedlist.print();
     */
    
    cout << endl;
    
    inFile.close();
    
    //opening it again for second timing procedure with Ordered list
    /**************************************************************************************/
    
    inFile.open(fileName.c_str());
    //getting the number of total elements in initial list and ignoring rest of line
    inFile >> numOfAdditions;
    getline(inFile, stuffToIgnore);
    //cout << endl << "this is the number of additions: " << numOfAdditions << endl;
    
    //creating orderedList
    OrderedList ourL(numOfAdditions, 0, numOfAdditions-1);
    //creating array for orderedList struct to use
    
    inFile >> addNum;
    ourL.ourList[0] = addNum;
    
    
    //getting the entire line of initial list into lineOfAdditions and parcing
    getline(inFile, lineOfAdditions);
    istringstream in2(lineOfAdditions);
    int i = 1;
    while (in2 >> addNum)
    {
        //cout << addNum << " ";
        ourL.ourList[i] = addNum;
        i++;
    }
    
    /*
    //printing first population of each list !!!!! MUTE LATER!!!!
    cout << endl << endl << "printing array ..." << endl;
    ourL.print(); */
    
    inFile >> numOfQueries;
    getline(inFile, stuffToIgnore);
    
    //cout << endl << "this is the number of queries: " << numOfQueries << endl;
    
    //everything works until here
    
    //queries
    getline(inFile, lineOfQueries);
    istringstream inn2 (lineOfQueries);
    
    start = std::chrono::system_clock::now();
    
    ourL.mergeSort(ourL.leftIndex, ourL.rightIndex);
    
    while (inn2 >> searchNum)
    {
        //cout << searchNum << " ";
        ourL.binarySearch(searchNum);
        
        
    }
    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_secondss = end - start;
    //std::time_t end_timee = std::chrono::system_clock::to_time_t(end);
    //cout << "finished computation at " << std::ctime(&end_timee)
    cout << "Time for orderedList: " << elapsed_secondss.count() << "s\n";
    cout << endl;
    
    /*
    cout << endl << "printing array after sort and search" << endl;
    ourL.print();
     */
    
    if (elapsed_secondss.count() < elapsed_seconds.count())
    {
        cout << "orderedList is faster than MTFList" << endl;
    }
    
    else
    {
        cout << "MTFList is faster than orderedList" << endl; 
    }
    
    cout << endl;
    
    inFile.close();

    return 0;
}
