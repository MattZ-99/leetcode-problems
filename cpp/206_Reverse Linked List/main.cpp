/* 206. Reverse Linked List
Easy

Given the head of a singly linked list, reverse the list, and return the reversed list. */

// Runtime: 5 ms, faster than 90.79% of C++ online submissions for Reverse Linked List.
// Memory Usage: 8.4 MB, less than 40.92% of C++ online submissions for Reverse Linked List.

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;


        ListNode * first = nullptr, * second = head, * third = head->next;
        while (true) {
            second->next = first;
            if (third == nullptr) break;
            first = second; second = third; third = third->next;
        }
        return second;        
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
    head = solution.reverseList(head);
    cout << "head: "; print_list_node(head);
}