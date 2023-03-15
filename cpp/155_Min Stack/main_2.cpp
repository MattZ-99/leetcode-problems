#include <stack>
#include <limits.h>
using namespace std;

// Runtime: 20 ms, faster than 80.84% of C++ online submissions for Min Stack.
// Memory Usage: 16.4 MB, less than 12.88% of C++ online submissions for Min Stack.

class MinStack {
private:
    stack<pair<int, int>> stackMin;
    int minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        minVal = min(minVal, val);
        stackMin.push({val, minVal});
    }
    
    void pop() {
        stackMin.pop();
        if(stackMin.empty()) minVal = INT_MAX;
        else minVal = getMin();
    }
    
    int top() {
        return stackMin.top().first;
    }
    
    int getMin() {
        return stackMin.top().second;
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