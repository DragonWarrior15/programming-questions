// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/ 
/*
Given a sorted linked list, delete all duplicates such that each element 
appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
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
        if(!head || !head->next){return head;}
        ListNode* original_head = new ListNode; original_head = head;
        while(head->next){
            if(head->next && head->val == head->next->val){
                // this way the duplicate will be "out" of the final list
                head->next = head->next->next;
            }else{
                // head pointer moves only in else because there can be
                // multiple duplicates which we want to repeatedly skip
                // over until different elements are observed
                head = head->next;
            }
        }
        return original_head;
    }
};
