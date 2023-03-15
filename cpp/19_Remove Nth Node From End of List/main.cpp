/* 19. Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head. */

// Runtime: 4 ms, faster than 81.15% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 10.7 MB, less than 74.82% of C++ online submissions for Remove Nth Node From End of List.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * first=head, * second=head;
        // move first poniter n positions.
        for (int i=0; i<n; i++) first = first->next;
        // remove head.
        if (first == nullptr) {
            second = second->next; delete head; return second;            
        }
        // remove intermediate node.
        first = first->next;
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        first = second->next;
        second->next = first->next;
        delete first;

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
    int n=2;

    // Solution.
    Solution solution;
    head = solution.removeNthFromEnd(head, n);
    cout << "head: "; print_list_node(head);

    return 0;
}