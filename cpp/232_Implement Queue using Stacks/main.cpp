/* 232. Implement Queue using Stacks
Easy

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 7.1 MB, less than 56.40% of C++ online submissions for Implement Queue using Stacks.

# include <iostream>
# include <stack>

using namespace std;

class MyQueue {
    stack<int> * stack_in, * stack_out;

public:
    MyQueue() {
        stack_in = new stack<int> ();
        stack_out = new stack<int> ();
    }
    
    void push(int x) {
        stack_in->push(x);
    }
    
    int pop() {
        int res = peek();
        stack_out->pop();
        return res;
    }
    
    int peek() {
        if (stack_out->empty()) {
            while (!stack_in->empty()) {
                stack_out->push(stack_in->top());
                stack_in->pop();
            }
        }
        
        return stack_out->top();
    }
    
    bool empty() {
        return (stack_in->empty() && stack_out->empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(3);
    obj->push(2);
    obj->push(1);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}