/*
Given a binary search tree, rearrange the tree in in-order so that the 
leftmost node in the tree is now the root of the tree, and every node 
has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Constraints:
    The number of nodes in the given tree will be between 1 and 100.
    Each node will have a unique integer value from 0 to 1000.
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
private:
    queue<TreeNode*> ans;
public:
    TreeNode* increasingBST(TreeNode* root) {
        // add the nodes in the new order to a queue
        addToQueue(root);
        // new node to store the tree
        TreeNode* curr_node = new TreeNode(ans.front()->val); ans.pop();
        // create new root for the rearranged tree
        TreeNode* new_root = curr_node;
        // add nodes to new tree in same order as queue
        while(!ans.empty()){
            TreeNode* new_node = new TreeNode(ans.front()->val); ans.pop();
            curr_node->right = new_node;
            curr_node = curr_node->right;
        }
        return new_root;
    }

    void addToQueue(TreeNode* node){
        // first add left subtree, then node and then right subtree
        if(node->left != NULL){
            addToQueue(node->left);
        }
        ans.push(node);
        if(node->right != NULL){
            addToQueue(node->right);
        }
    }
};
