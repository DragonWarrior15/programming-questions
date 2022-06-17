// https://leetcode.com/problems/palindrome-linked-list/
/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(!head){return true;}
        if(!head->next){return true;}
        int l = 0;
        ListNode *node = head;
        // find the length to get the mid point
        while(node){
            l++; node = node->next;
        }
        int n = l;
        l = 0; node = head;
        while(l < n/2){
            // cout << node->val << l << endl;
            node = node->next;
            l++;
        }
        // find the mid point and then reverse the list ahead of that
        // this way we get two lists that should be the same in case
        // of palindrome and this can be verified by a simple linear travel
        node = reverseList(node);
        while(head && node){
            if(head->val != node->val){
                return false;
            }
            head = head->next;
            node = node->next;
        }
        return true;
        }

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
