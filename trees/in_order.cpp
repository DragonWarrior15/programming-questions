/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
Problem 94

Given the root of a binary tree, return the inorder traversal of its nodes' values.
Input: root = [1,null,2,3]
Output: [1,3,2]
Input: root = []
Output: []
Input: root = [1]
Output: [1]
Input: root = [1,null,2]
Output: [1,2]
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        vector<int> left = inorderTraversal(root->left);
        for(int i = 0; i < left.size(); i++){
            ans.push_back(left[i]);
        }
        ans.push_back(root->val);
        left = inorderTraversal(root->right);
        for(int i = 0; i < left.size(); i++){
            ans.push_back(left[i]);
        }
        return ans;
    }
};
