// Noor Sakoki, Jingtang Ma, Feng Zheng
// CS303
// Libraries
#include<iostream>
#include "Morse Tree.hpp"
using namespace std;

// Main
int main()
{
    // Declare Variables
    Morse_Tree obj;
    Node *root;
    
    // Create root of morse code
    root = obj.create_tree(5);
    obj.morse_code(root);
    
    // Decode userinput morse code
    obj.DECODE(root,"._ _._. ... __..");
    
    // Encode userinput morse code
    obj.ENCODE(root, "abcxyz");
    
    cout << endl<<endl;
    return 0;
}
