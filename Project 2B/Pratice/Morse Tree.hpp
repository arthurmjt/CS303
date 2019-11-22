
#ifndef Morse_Tree_hpp
#define Morse_Tree_hpp
#include <stdio.h>
#endif /* Morse_Tree_hpp */
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    string code;
    char letter;
    Node(){ code = " "; letter = ' '; }

};

class Morse_Tree{
    
private:
    string code;
    char decode(Node *root, string input);
    
public:
    Morse_Tree(){ };
    Node* create_tree(int depth);
    void morse_code(Node *root);
    void insert(Node *root , char l, string c);
    void DECODE(Node *root,string input);
    void ENCODE(Node *root, string input);
    void search(Node *root, char i);
};
