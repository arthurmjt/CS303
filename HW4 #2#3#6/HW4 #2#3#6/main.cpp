//
//  main.cpp
//  HW4 #2#3#6
//
//  Created by Arthur on 10/13/19.
//  Copyright © 2019 Arthur. All rights reserved.
//


//Q2
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int to_number (string str) {
   if(str == " " || str == "" || str.length() == 0)
   {
       return 0;
   }
    if(isdigit(str[0]))
    {
       return str[0] - '0' + to_number(str.substr(1));
    }
    else
    {
      return to_number(str.substr(1));
    }

}

//Q3

int find_last(int vec[],int target,int size)
{
    if(size <0)
    {
        return 0;
    }
    if(vec[size] == target)
    {
        cout << target <<" is found at position " << size << endl;
        return target;
    }
    else
    {
        return find_last(vec,target,size-1);
    }
}

//Q6 Pseudo code

void insertion_sort(list<int> &myL) {
    bool insertionNeeded = false;
    list<int>::iterator iter = myL.begin();
    for (int j = 1; j <= myL.size(); j++) {
        insertionNeeded = false;
        for (int i = j - 1; myL.size()-j; i++)
        { // larger values move right
            list<int>::iterator temp_iter = iter;
            if (*++iter == *temp_iter)
            {
                swap(*iter,*temp_iter);
                insertionNeeded = true;
            }

        }
        if (!insertionNeeded)
        {
            break;
        }
        else if(insertionNeeded)
        {
            
        myL[i + 1] = key; //Put key into its proper location
        }
    }
}

