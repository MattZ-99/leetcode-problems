/* 141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list 
if there is some node in the list that can be reached again 
by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false. */

/* 
Runtime: 24 ms, faster than 14.88% of C++ online submissions for Linked List Cycle.
Memory Usage: 10.4 MB, less than 12.60% of C++ online submissions for Linked List Cycle.
*/

# include <iostream>
# include <cstdio>
# include <vector>
# include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> ptr_set;
        while (head != NULL) {
            if (ptr_set.count(head)) return true;
            ptr_set.insert(head);
            head = head->next;
        }
        return false;
    }
};


int main() { 
    printf("#%s\n\n", "141. Linked List Cycle");
    
    vector<int> values{3,2,0,-4};
    ListNode *head, *crt;

    head = new ListNode(0);
    crt = head;
    for (int val:values) {
        crt->next = new ListNode(val);
        crt = crt->next;
    }
    crt->next = head->next->next;

    crt = head->next;
    delete head;
    head = crt;

    // crt = head;
    // while (crt != NULL) {
    //     cout << crt->val << ' ';
    //     crt = crt->next;
    // }
    // cout << '\n';

    Solution s;
    cout << s.hasCycle(head) << endl;
    

    return 1;
}