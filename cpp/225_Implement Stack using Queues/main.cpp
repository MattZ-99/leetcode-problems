/* 225. Implement Stack using Queues


Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 6.8 MB, less than 93.49% of C++ online submissions for Implement Stack using Queues.

# include <iostream>
# include <queue>

using namespace std;

class MyStack {
    queue<int> * my_queue, * backup_queue;

    int get_the_final_element() {
        while (my_queue->size() > 1) {
            backup_queue->push(my_queue->front());
            my_queue->pop();
        }
        return my_queue->front();
    }

public:
    MyStack() {
        my_queue = new queue<int> ();
        backup_queue = new queue<int> ();
    }
    
    void push(int x) {
        my_queue->push(x);
    }
    
    int pop() {
        int res = get_the_final_element();

        my_queue->pop();
        swap(my_queue, backup_queue);
        
        return res;
    }
    
    int top() {
        int res = get_the_final_element();

        backup_queue->push(my_queue->front());
        my_queue->pop();
        swap(my_queue, backup_queue);
        
        return res;
    }
    
    bool empty() {
        return (*my_queue).empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack* obj = new MyStack();

    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    cout << param_2 << endl;
    return 0;
}