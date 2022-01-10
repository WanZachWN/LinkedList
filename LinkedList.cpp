#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    cout << "Destroying LinkedList" << endl;
    while(head != nullptr) {
        DeleteLastNode();
    }
}

int LinkedList::Insert(int data) {
    if(head == nullptr && tail == nullptr) {
        head = new Node();
        head->data = data;
        head->next = nullptr;
        tail = head;
        cout << "Inserting " << data;
        cout << " | Head points to " << head->data
             << " | Tail points to " << tail->data << endl;
        return 0;
    }
    Node* temp = tail;
    temp->next = new Node();
    temp->next->data = data;
    temp->next->next = nullptr;
    tail = temp->next;
    cout << "Inserting " << data
         << " | Tail points to " << tail->data << endl;

    return 0;
}

int LinkedList::DeleteLastNode() {
    if(head == nullptr && tail == nullptr) {
        return 0;
    } else if(head == tail) {
        tail = nullptr;
        cout << "Deleting " << head->data << endl;
        delete head;
        head = nullptr;
        return 0;
    }
    Node* temp = head;
    while(temp->next != tail) {
        temp = temp->next;
    }
    cout << "Deleting " << temp->next->data << endl;
    temp->next = nullptr;
    delete tail;
    tail = temp;
    return 0;
}

int LinkedList::Print() {
    Node* iterator = head;
    int counter = 0;
    cout << endl << "head ==> ";
    do{ 
        cout << "Iterator is at " << counter << " ";
        cout << "| Node: " << counter 
             << " -- Data: " << iterator->data 
             << ", Address: " << iterator;
        
        if(iterator != tail) {
            cout << "| ==>" << endl;
        }
        iterator = iterator->next;
        ++counter;

    }while(iterator != nullptr);

    cout << " <== tail";
    cout << endl;
    return 0;
}

//Optimize this code
int LinkedList::AtIndex(int counter) {
    Node* iterator = head;
    for(int it = 0; it != counter; it++){
        if(iterator->next != nullptr) {
            iterator = iterator->next;
        } else {
            return -1;
        }
    }
    return iterator->data;
}

int LinkedList::GetIndex(int data) {
    Node* iterator = head;
    int counter = 0;
    while(iterator->next != nullptr) {
        if(iterator->data == data){
            return counter;
        }
        iterator = iterator->next;
        ++counter;
    }
    return -1;
}
