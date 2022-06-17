// https://leetcode.com/problems/diameter-of-binary-tree/
/*
Given a binary tree, you need to compute the length of the diameter 
of the tree. The diameter of a binary tree is the length of the longest 
path between any two nodes in a tree. This path may or may not pass 
through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of 
edges between them. 
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // for each node, store the max depth in the node's value
        get_max_depth(root);
        // now get the max of left + right for each node
        int ans = 0, temp_ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto n = s.top(); s.pop();
            temp_ans = 1;          
            // add new nodes to the stack
            if(n->left != NULL){
                s.push(n->left);
                temp_ans += n->left->val;
                // cout << n->val << " " << temp_ans << endl;
            }
            if(n->right != NULL){
                s.push(n->right);
                temp_ans += n->right->val;
                // cout << n->val << " " << temp_ans << endl;
            }
            ans = max(ans, temp_ans);
        }
        // the ans calculated is the number of nodes
        // edges will be number of nodes - 1
        if(ans <= 1){return 0;}
        return ans-1;
    }

    int get_max_depth(TreeNode* node){
        if(node == NULL){
            return 0;
        }else{
            node->val = 1 + max(get_max_depth(node->left), get_max_depth(node->right));
            return node->val;
        }
    }
};
