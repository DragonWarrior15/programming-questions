// https://leetcode.com/problems/reverse-linked-list/
/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. 
Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(!head){return NULL;}
        if(!head->next){return head;}
        // maintain three pointers and shift accordingly
        ListNode *n = nullptr;
        ListNode *h = head;
        ListNode *t = head->next;
        while(t){
            head->next = n;
            n = head;
            head = t;
            t = t->next;
        }
        head->next = n;
        return head;
    }
};