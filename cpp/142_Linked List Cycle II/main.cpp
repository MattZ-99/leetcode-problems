/* 142. Linked List Cycle II
Medium

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list. */

// Runtime: 14 ms, faster than 64.00% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.4 MB, less than 89.93% of C++ online submissions for Linked List Cycle II.


#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode * fast_ptr=head, * slow_ptr=head;

        while (true) {
            if (!fast_ptr->next || !fast_ptr->next->next) return nullptr;
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if (fast_ptr == slow_ptr) break;
        } 

        slow_ptr = head;
        while(true) {
            if (fast_ptr == slow_ptr) return fast_ptr;
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }        
    }
};

ListNode * create_cycle_list(vector<int> & arr, int pos) {
    ListNode * head = new ListNode(0), * temp_ptr=head, * cycle_node;
    for (auto i: arr) {
        temp_ptr->next = new ListNode(i);
        temp_ptr = temp_ptr->next;
    }

    cycle_node = head;
    head = head->next;
    delete cycle_node;

    if (pos == -1) return head;
    cycle_node = head;
    for (int i=0; i<pos; i++) cycle_node = cycle_node->next;       
    temp_ptr->next = cycle_node;
    return head;
}

void print_cycle_list(ListNode * head, int max_length=10) {
    for (int i=0; i<max_length; i++) {
        if (!head) break;
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}


int main() {
    // Inputs.
    vector<int> val_arr = {3,2,0,-4};
    int pos = 1;
    ListNode * head = create_cycle_list(val_arr, pos);
    cout << "head: "; print_cycle_list(head);

    // Solution.
    Solution solution;
    ListNode * cycle_node = solution.detectCycle(head);
    if (cycle_node) cout << cycle_node->val << endl;

    return 0;
}