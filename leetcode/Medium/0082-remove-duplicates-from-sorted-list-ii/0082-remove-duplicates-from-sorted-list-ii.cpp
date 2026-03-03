/*
 Problem: 82. Remove Duplicates from Sorted List II
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15.6 MB (92.05%)
 Tags: Linked List, Two Pointers
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                prev->next = curr->next;
            }
            
            curr = curr->next;
        }

        return dummy.next;
    }
};