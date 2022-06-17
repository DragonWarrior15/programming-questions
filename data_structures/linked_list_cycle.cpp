// https://leetcode.com/problems/linked-list-cycle/submissions/
/*
determine if the given linked list has a cycle, the head of the
list is provided as input. if there is no cycle, return false else true
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){return false;}
        ListNode* slow = new ListNode; slow = head;
        ListNode* fast = new ListNode; fast = head;
        while(fast->next && fast->next->next && slow->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
