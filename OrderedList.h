//
//  OrderedList.h
//  P1
//
//  Created by Samantha Ho on 9/29/19.
//  Copyright © 2019 Samantha Ho. All rights reserved.
//

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <stdio.h>
#include <array>
#include <vector>
#include <iostream>
#include<stdlib.h>
#include<stdio.h> 
using namespace std;

struct OrderedList
{

    int arraysize;
    int leftIndex;
    int rightIndex;
    int* ourList;
    

    OrderedList();
    OrderedList(int arrsize, int L, int R);
    
    void mergeSort(int l, int r);
    void merge(int l, int m, int r);
    int binarySearch(int searchItem);
    void print();
    
    
};

OrderedList::OrderedList()
{
    //default constructor
    arraysize = 0;
    leftIndex = 0;
    rightIndex = 0;
    ourList = NULL;
    
}

OrderedList::OrderedList(int arrsize, int L, int R)
{
    arraysize = arrsize;
    leftIndex=L;
    rightIndex=R;
    ourList = new int[arrsize];
}


void OrderedList::merge(int l, int m, int r)
{
    int i, j, k;
    
    //sizes for helper arrays
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    //helper arrays
    int L[n1], R[n2];
    
    //copying left and right sides of numbers to their appropriate helper array
    for (i = 0; i < n1; i++)
        L[i] = ourList[l + i];
    for (j = 0; j < n2; j++)
        R[j] = ourList[m + 1+ j];
    
    //merge back into one full array from leftindex to rightindex
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ourList[k] = L[i];
            i++;
        }
        else
        {
            ourList[k] = R[j];
            j++;
        }
        k++;
    }
    
    //copying any remaining elements of L
    while (i < n1)
    {
        ourList[k] = L[i];
        i++;
        k++;
    }
    
    //copying any remaining elements of R
    while (j < n2)
    {
        ourList[k] = R[j];
        j++;
        k++;
    }
}


void OrderedList::mergeSort(int l, int r)
{
    if (l < r)
    {
        //int m = l+(r-l)/2;
        int m = (l+r)/2;
        
        //first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int OrderedList::binarySearch (int searchItem)
{
    int first = 0;
    int last = arraysize - 1;
    int mid;
    bool found = false;
    string errMessageUnknown = " ";
    string errMessageNotFound = "caught logic error in binary search method";
    
    try
    {
        while (first <= last && !found)
        {
            mid = (first+last)/2;
            if (ourList[mid] == searchItem)
            {
                found = true;
            }
            else if (ourList[mid] > searchItem)
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        }// end while
        if (!found)
        {
            return -1;
            throw logic_error(errMessageNotFound);
        }//end if
    }// end try
    catch(logic_error &e)
    {
        cout << e.what();
        //throw;//point is, you don't want the return at the bottom to happen
    }
    catch(...)
    {
        errMessageUnknown = "unknown exception caught in binary  search method";
        cout << errMessageUnknown << endl;
        //throw;
    }
    
    //returns index
    return mid;
}

void OrderedList::print()
{
    int i;
    for (i=0; i < arraysize; i++)
    {
        cout << "  " << ourList[i] << "  ";
    }
    cout << endl;
}



#endif /* OrderedList_h */
