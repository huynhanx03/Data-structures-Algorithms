/*
 Problem: 23. Merge k Sorted Lists
 Language: cpp
 Runtime: 17 ms (19.79%)
 Memory: 23.8 MB (6.25%)
 Tags: Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
*/
/**
 * Definition for singly-linked list->
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0)
            return nullptr;

        return sortLists(lists, 0, n - 1);
    }

    ListNode* sortLists(vector<ListNode*>& lists, int left, int right) {
        if (left == right)
            return lists[left];
        
        if (right - left == 1)
            return mergeList(lists[left], lists[right]);

        int mid = left + (right - left) / 2;

        ListNode* listLeft = sortLists(lists, left, mid);
        ListNode* listRight = sortLists(lists, mid + 1, right);

        return mergeList(listLeft, listRight);
    }

    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* listMerge = new ListNode(0);
        ListNode* tmp = listMerge;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }

            tmp = tmp->next;
        }

        tmp->next = list1 ? list1 : list2;

        return listMerge->next;
    }
};