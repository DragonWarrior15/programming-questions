// https://leetcode.com/problems/maximum-depth-of-binary-tree/
/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // recurse
        if(root->left == NULL and root->right == NULL){
            // leaf node
            return 1;
        }else if(root->left == NULL){
            return 1 + maxDepth(root->right);
        }else if(root->right == NULL){
            return 1 + maxDepth(root->left);
        }else{
            return 1 + max(maxDepth(root->right), maxDepth(root->left));
        }
        return 1;
    }
};
