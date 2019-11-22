//  Morse Tree.cpp

#include<iostream>
#include<string>
#include<fstream>
#include "Morse Tree.hpp"
using namespace std;

// Decode the morse code
char Morse_Tree::decode(Node *root, string input){
        
    Node *current = root;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '_') {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    
    return current->letter;
}

// Create tree
Node* Morse_Tree::create_tree(int depth){
    
    Node *node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->code = " ";
    if(depth == 1){
        return node;
    }
    node->left = create_tree(depth - 1);
    node->right = create_tree(depth - 1);
    return node;
}

// Read the morse code
void Morse_Tree::morse_code(Node *root) {

    char l_arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l'
        ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string c_arr[26] = {
        "._","_...","_._.","_..",".",".._.","__.","....","..",
        ".___","_._","._..","__","_.","___",".__.","__._","._.",
        "...","_",".._","..._",".__","_.._","_.__","__.."
    };
    for (int i = 0; i < 26; i++) {
        insert(root, l_arr[i], c_arr[i]);
    }
}

// Insert morse code into tree
void Morse_Tree::insert(Node *root , char l, string c) {
    
    Node *current = root;
    for (int i = 0; i < c.length(); i++) {
        if (c[i] == '_') {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    
    current->letter = l;
    current->code = c;
}

// Decode userinput morse code
void Morse_Tree::DECODE(Node *root,string input ) {
    
    int num_letters = 0;
    int count = 0;
    string *codes;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            num_letters++;
    }
    
    codes = new string[num_letters + 1];
    for (int i = 0; i<input.length(); i++) {
        if (input[i] != ' '){
            codes[count] += input[i];
        }
        if (input[i] == ' '){
            count++;
        }
    }

    cout << "The decoded message is: ";
    for (int i = 0; i < num_letters + 1; i++)
        cout << decode(root, codes[i]) << " ";
}

// Encode userinput morse code
void Morse_Tree::ENCODE(Node *root, string input) {
    
    Node *current = root;
    cout << "\nEncoded Message is: ";
    for (int i = 0; i < input.length(); i++) {
        search(current, input[i]);
        cout << code<<" ";
    }
}

// Search matched morse code in tree
void Morse_Tree::search(Node *root, char i) {
    
    if (root) {
        if (i == root->letter){
        code=root->code;
        }
        
        search(root->left, i);
        search(root->right, i);
    }
}
