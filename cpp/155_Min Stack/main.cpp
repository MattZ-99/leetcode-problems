#include <iostream>
#include <limits.h>
using namespace std;

// Runtime: 28 ms, faster than 17.07% of C++ online submissions for Min Stack.
// Memory Usage: 16.8 MB, less than 7.36% of C++ online submissions for Min Stack.

class MinStack {
private:

    struct Node {
        int val;
        int minVal;
        Node *next;
        Node *prev;
    };
    Node *head = NULL;
    Node *tail = NULL;
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new Node;
        head->minVal = INT_MAX;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    
    void push(int val) {
        Node * node = new Node;
        node->val = val;
        node->minVal = min(tail->minVal, val);
        node->next = NULL;
        node->prev = tail;
        tail = node;
    }
    
    void pop() {
        Node * node = tail;
        tail = node->prev;
        delete node;
    }
    
    int top() {
        return tail->val;
    }
    
    int getMin() {
        return tail->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */