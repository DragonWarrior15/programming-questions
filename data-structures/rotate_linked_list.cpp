// https://leetcode.com/problems/rotate-list/https://leetcode.com/problems/rotate-list/
/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0){return head;}
        if(head == NULL){return head;}
        ListNode* node = new ListNode;
        // get the length of list to do k modulo n
        node = head; int n = 1;
        while(node->next){
            n++; node = node->next;
        }
        k = k%n;
        if(k == 0){return head;}
        ListNode* new_head = new ListNode;
        // traverse the list to reach new head
        // maths -> rank from top + rank from bottom - 1 = total objects
        int i = 1; node = head;
        while(i < n-k+1){
            node = node->next; i++;
        }
        new_head = node;
        // find the element just before the new head, this becomes new tail
        node = head; i = 1;
        while(i < n-k){
            node = node->next; i++;
        }
        node->next = nullptr;
        // the last element of the original list points to the original head
        // to complete the list
        node = new_head;
        while(node->next){
            node = node->next;
        }
        node->next = head;
        // return new head
        return new_head;
    }
};