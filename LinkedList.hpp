#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "..\Node\Node.hpp"
#include <iostream>
using namespace std;

class LinkedList{

    private:
        Node* head;
        Node* tail;

    public:
        LinkedList();
        ~LinkedList();
        int Insert(int data);
        int DeleteLastNode();
        int Print();
        int AtIndex(int counter);
        int GetIndex(int data);
};

#endif