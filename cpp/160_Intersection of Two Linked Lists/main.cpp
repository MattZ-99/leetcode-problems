/* 160. Intersection of Two Linked Lists
Easy

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null. 
*/

// Runtime: 46 ms, faster than 95.88% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 14.5 MB, less than 72.91% of C++ online submissions for Intersection of Two Linked Lists.

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode * getIntersectionNodeWithLength(ListNode *headA, ListNode *headB, int len_a, int len_b) {
        // List A is the shorter one.
        for (int i=0; i<len_b - len_a; i++) headB = headB->next;

        while(true) {
            if (headA == nullptr || headB == nullptr) return nullptr;
            if (headA == headB) return headA;
            headA = headA->next; headB = headB->next;
        }
        return nullptr;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * node1, * node2;
        int len_a=1, len_b=1;

        node1 = headA;
        while (true) {
            if (!node1->next) break;
            node1 = node1->next;
            len_a++;
        }

        node2 = headB;
        while (true) {
            if (!node2->next) break;
            node2 = node2->next;
            len_b++;
        }

        if (node1 != node2) return nullptr;
        if (len_a<len_b) return getIntersectionNodeWithLength(headA, headB, len_a, len_b);
        else return getIntersectionNodeWithLength(headB, headA, len_b, len_a);
    }
};

pair<ListNode *, ListNode *> create_interacted_list(vector<int> & listA, vector<int> & listB, int intersectVal, int skipA, int skipB) {
    ListNode * headA, * headB, * temp_ptr, * intersect_ptr;
    headA = new ListNode(0); headB = new ListNode(0);

    temp_ptr = headA;
    for (int i=0; i<skipA; i++) {
        temp_ptr->next = new ListNode(listA[i]);
        temp_ptr = temp_ptr->next;
    }
    intersect_ptr = temp_ptr;

    temp_ptr = headB;
    for (int i=0; i<skipB; i++) {
        temp_ptr->next = new ListNode(listB[i]);
        temp_ptr = temp_ptr->next;
    }

    temp_ptr->next = new ListNode(listB[skipB]);
    intersect_ptr->next = temp_ptr->next;
    intersect_ptr = intersect_ptr->next;

    temp_ptr = intersect_ptr;
    for (auto iter = listB.begin() + skipB + 1; iter<listB.end(); iter++) {
        temp_ptr->next = new ListNode(*iter);
        temp_ptr = temp_ptr->next;
    }

    temp_ptr = headA; headA = headA->next; delete temp_ptr;
    temp_ptr = headB; headB = headB->next; delete temp_ptr;

    return {headA, headB};
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
    int intersectVal = 8, skipA = 2, skipB = 3;
    vector<int> listA = {4,1,8,4,5}, listB = {5,6,1,8,4,5};
    auto head_pair = create_interacted_list(listA, listB, intersectVal, skipA, skipB);
    ListNode * headA = head_pair.first, * headB = head_pair.second;
    cout << "head A: "; print_list_node(headA);
    cout << "head B: "; print_list_node(headB);

    // Solution.
    Solution solution;
    ListNode * intersec_node = solution.getIntersectionNode(headA, headB);

    cout << "Intersect value: " << intersec_node->val << endl;

    return 0;
}