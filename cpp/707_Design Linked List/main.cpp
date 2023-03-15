/* 707. Design Linked List
Medium

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid. */


// Runtime: 52 ms, faster than 79.66% of C++ online submissions for Design Linked List.
// Memory Usage: 19.6 MB, less than 89.21% of C++ online submissions for Design Linked List.

#include <iostream>
using namespace std;


class MyLinkedList {
    MyLinkedList * next;
    int val;
public:
    MyLinkedList() : val(0), next(nullptr)  {}
    MyLinkedList(int val) : val(val), next(nullptr) {}
    MyLinkedList(int val, MyLinkedList * next) : val(val), next(next) {}
    MyLinkedList(MyLinkedList * head) : val(head->val), next(head->next) {}
    
    int get(int index) {
        MyLinkedList * temp_node = this->next;
        for (int i=0; i<index; i++) {
            if (temp_node == nullptr) return -1;
            temp_node = temp_node->next;
        }
        if (temp_node == nullptr) return -1;
        return temp_node->val;
    }
    
    void addAtHead(int val) {
        MyLinkedList * new_node = new MyLinkedList(val, this->next);
        this->next = new_node;        
    }
    
    void addAtTail(int val) {
        MyLinkedList * new_node = this;
        // find tail.
        while (true) {
            if (new_node->next == nullptr) {new_node->next = new MyLinkedList(val); break;}
            new_node = new_node->next;
        }   
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList * new_node = this;
        for (int i=0; i<index; i++) {
            new_node = new_node->next;
            if (new_node == nullptr) return;
        }
        new_node->next = new MyLinkedList(val, new_node->next);
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList * new_node = this, * temp_node;
        for (int i=0; i<index; i++) {
            new_node = new_node->next;
            if (new_node == nullptr) return;
        }

        if (new_node->next == nullptr) return;
        temp_node = new_node->next; new_node->next = temp_node->next;
        delete temp_node;
    }
};


int main() {
    // Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    cout << obj->get(0) << obj->get(1) << obj->get(2) << endl;
    obj->addAtHead(1);
    cout << obj->get(0) << obj->get(1) << obj->get(2) << endl;
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout << obj->get(0) << obj->get(1) << obj->get(2) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(0) << obj->get(1) << obj->get(2) << endl;

    return 0;
}

