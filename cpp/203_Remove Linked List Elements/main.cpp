/* 
203. Remove Linked List Elements
Easy

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * first, * second;
        // remove head values.
        first = head;
        while (true) {
            if (first == nullptr) return head;
            if (first->val != val) break;
            // delete the node.
            first = head->next;
            delete head;
            head = first;
        }

        // remove interval values.
        while (true) {
            second = first->next;
            if (second == nullptr) return head;
            if (second->val == val) {
                // delete the node.
                first->next = second->next;
                delete second;
            }
            else first = first->next;
        }
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

int main(){
    // Inputs.

    vector<int> val_list = {1,2,6,3,4,5,6};
    int val = 6;

    // vector<int> val_list = {7,7,7,7};
    // int val = 7;

    // vector<int> val_list = {};
    // int val = 7;

    ListNode * head = construct_list_node(val_list);

    cout << "head: "; print_list_node(head);

    // Solution.
    Solution solution;
    head = solution.removeElements(head, val);
    cout << "head: "; print_list_node(head);
}