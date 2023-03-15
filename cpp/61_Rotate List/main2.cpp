/* 61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.
*/

// Runtime: 7 ms, faster than 81.86% of C++ online submissions for Rotate List.
// Memory Usage: 11.6 MB, less than 99.29% of C++ online submissions for Rotate List.

# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;

        ListNode* origin_ptr=head;
        int listLen = 1;
        while(origin_ptr->next) { origin_ptr = origin_ptr->next; listLen++; }
        origin_ptr->next = head;

        k = listLen - k % listLen - 1;
        origin_ptr = head;
        while(k>0) { origin_ptr = origin_ptr->next; k--; }
        head = origin_ptr->next;
        origin_ptr->next = nullptr;
        return head;
    }
};

void outputNodeList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    printf("#%s\n\n", "61. Rotate List");
    vector<int> node_val{1,2,3,4,5};
    ListNode* head = new ListNode, *cnt=head;
    for (int val: node_val) {
        cnt->next = new ListNode(val);
        cnt = cnt->next;
    }
    cnt = head-> next;
    delete head;
    head = cnt;
    outputNodeList(head);
    int k = 2;

    Solution s;
    ListNode* rotatedRightList = s.rotateRight(head, k);
    outputNodeList(rotatedRightList);

    return 1;
}