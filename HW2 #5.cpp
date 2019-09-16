//
//  HW2 #5.cpp
//  HW2 #5
//
//  Created by Jingtang Ma on 9/15/19.
//

#include <stdio.h>
//HW2 #5
//a
Node<string>* Bill = new Node<string>("Bill");
Bill->next = Tom;
Head = Bill;

//b
Node<sting>* Sue = new Node<string>("Sue");
Sue->next = harry->next;
harry->next = Sue;

//c
Node<string>* ptr = head;
Head = head->next;
Delete ptr;

//d
Node<string>* temp_node = head;
while(temp_node != NULL){
    If (temp_node->next->next = NULL){
        delete temp-node->next;
    }
    temp_node = temp_node->next;
}
