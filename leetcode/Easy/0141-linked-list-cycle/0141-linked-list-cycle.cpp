/*
 Problem: 141. Linked List Cycle
 Language: cpp
 Runtime: 14 ms (10.26%)
 Memory: 15 MB (5.78%)
 Tags: Hash Table, Linked List, Two Pointers
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        set<ListNode*> st;
        while (head != nullptr) {
            if (st.find(head) != st.end())
                return true;
            
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};