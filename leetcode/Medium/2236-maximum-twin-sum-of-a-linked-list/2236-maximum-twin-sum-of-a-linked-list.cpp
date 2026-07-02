/*
 Problem: 2236. Maximum Twin Sum of a Linked List
 Language: cpp
 Runtime: 4 ms (57.07%)
 Memory: 124.3 MB (67.93%)
 Tags: Linked List, Two Pointers, Stack
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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *cur = slow;

        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        int ans = 0;

        while (prev) {
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return ans;
    }
};