/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // base case if the root is null
        if(root == nullptr){
            return ans;
        }
        // do a bfs and store the elements in a vector
        // define a level vector to decide when the vector storing the
        // answer should change
        int level = 0;
        // store the intermediate answers in ans1
        vector<int> ans1;
        // queue to store the elements for bfs
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> temp_pair;
        // push the root element
        q.push({root, level});
        // travel the queue while it is not empty
        while(!q.empty()){
            // get the current element and add it to the ans vector
            // depending on the level
            temp_pair = q.front();
            // pop returns null and removes the first element
            q.pop();
            if(temp_pair.second != level){
                // add ans1 to ans
                ans.push_back(ans1);
                // clear the ans vector and then add
                ans1.erase(ans1.begin(), ans1.end());
                // increment level by 1
                level++;
            }
            // add to the same ans vector
            ans1.push_back(temp_pair.first->val);
            // now add the children of this element to the queue
            if(temp_pair.first->left){
                q.push({temp_pair.first->left, level + 1});
            }
            if(temp_pair.first->right){
                q.push({temp_pair.first->right, level + 1});
            }
        }
        // if ans1 still has some elements, add to ans
        if(ans1.size() != 0){
            ans.push_back(ans1);
        }
        // return the answer
        return ans;
    }
};
