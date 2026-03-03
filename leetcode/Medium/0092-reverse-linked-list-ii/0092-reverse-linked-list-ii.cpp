/*
 Problem: 92. Reverse Linked List II
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.1 MB (71.15%)
 Tags: Linked List
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        
        for (int i = 0; i < right - left; ++i) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};