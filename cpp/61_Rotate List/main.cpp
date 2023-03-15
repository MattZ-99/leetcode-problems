/* 61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.
*/

// Runtime: 8 ms, faster than 71.83% of C++ online submissions for Rotate List.
// Memory Usage: 11.8 MB, less than 7.34% of C++ online submissions for Rotate List.

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
        if (head == nullptr) return nullptr;

        ListNode* rotatedList=new ListNode, * origin_ptr=head, * rotated_ptr=rotatedList;
        int listLen = 0;
        while(origin_ptr) {
            rotated_ptr->next = new ListNode(origin_ptr->val);
            rotated_ptr = rotated_ptr->next;
            origin_ptr = origin_ptr->next;
            listLen++;
        }
        rotated_ptr->next = rotatedList->next;
        delete rotatedList;
        rotatedList = rotated_ptr->next;

        k = listLen - k % listLen;
        while(k>0) {
            rotated_ptr = rotatedList;
            rotatedList = rotatedList->next;
            k--;
        }
        rotated_ptr->next = nullptr;
        return rotatedList;
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