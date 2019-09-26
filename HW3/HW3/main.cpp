//
//  main.cpp
//  HW3
//
//  Created by Arthur on 9/25/19.
//  Copyright © 2019 Arthur. All rights reserved.
//

#include <iostream>
using namespace std;

// Question 3
string reverse(string& str) // passing by reffernce to change the original string.
{
    stack<string>myS; // stack will hold the words.
    string temp="";
    for(int i = 0; i< str.size()+1;i++)
    {
        if(str[i] != ' ' && str[i] != '\0') // if the char we iterating is not ' ' and not the end then add it to a temp string.
        {
            temp +=str[i];
        }
        else
        {
            myS.push(temp); //if we have a complete word, then add it to the stack.
            temp.clear(); // clear the word from temp. to take the next word.
        }}
    str = ""; // empty the original string.
    
    while(!myS.empty())
    {
        // while the stack is not empty then add the top word in the stack to the string + ' ', then pop it.
        str +=myS.top();
        str += ' ';
        myS.pop();
    }
    return str; // return the reversed string.
}


//Question 7
//1-    Check if the queue is not empty(), otherwise, print to user that it is empty:
    if (myQ.empty())
    {
            cout << "the queue is empty" << endl;
    }

//2-    Print the front element using front():
cout << myQ.front() << " ";

//3-    Pop that element using pop():
            myQ.pop();

//4-    Finally, put all this codes in a while loop to get:

    if (myQ.empty())
        {
            cout << "the queue is empty" << endl;
        }
    
    while(!myQ.empty())
        {
            cout << myQ.front() << " ";
            myQ.pop();
   }

// using this simple algorithm will empty our queue at the end since we will be popping all the items to display them.
// we can avoid this by having a temp stack and store the items before popping them from the queue and then restore the items to queue again.

//Question 8
        void move_to_rear(queue<ItemType> myQ)
            {
                    int temp = myQ.front();
                    myQ.pop();
                    myQ.push(temp);
                    
                    while (!myQ.empty())
                    {
                        cout << myQ.front() << " ";
                        myQ.pop();
                    }
                    cout << endl;
        }

