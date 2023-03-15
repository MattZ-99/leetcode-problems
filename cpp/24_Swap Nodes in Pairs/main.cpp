/* 24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.) */

// Runtime: 3 ms, faster than 77.89% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.5 MB, less than 91.53% of C++ online submissions for Swap Nodes in Pairs.

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Return directly if list is short (0 or 1).
        if (head == nullptr || head->next == nullptr) return head;

        ListNode * first=head, * second=head->next;
        // Swap head two nodes.
        first->next = second->next; second->next = first; head = second;

        // Swap the remaining nodes.
        while (true) {
            second = first->next;
            if (second == nullptr || second->next == nullptr) break;
            first->next = second->next; first = first->next;
            second->next = first->next; first->next = second;
            first = second;
        }
        return head;
    }
};

ListNode* construct_list_node(vector<int>& val_list) {
    ListNode * head, * tail, * temp;
    head = new ListNode;
    tail = head;

    for (auto val: val_list) {
        temp = new ListNode(val);
        tail->next = temp;
        tail = tail->next;
    }
    temp = head->next;
    delete head;

    return temp;
}

void print_list_node(ListNode * head) {
    while (true) {
        if (head == nullptr) break;
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

int main() {
    // Inputs.
    vector<int> val_list = {1,2,3,4,5};
    ListNode * head = construct_list_node(val_list);
    cout << "head: "; print_list_node(head);

    // Solution.
    Solution solution;
    head = solution.swapPairs(head);
    cout << "head: "; print_list_node(head);

    return 0;
}