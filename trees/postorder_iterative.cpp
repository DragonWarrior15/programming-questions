// https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/
/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order 
traversal, each group of children is separated by the null value 
(See examples).

Follow up:
Recursive solution is trivial, could you do it iteratively? 

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1] 

Constraints:
    The height of the n-ary tree is less than or equal to 1000
    The total number of nodes is between [0, 10^4]
*/

/*
Logic: we try to do the solution recursively
notice that, if we first try to get the reverse of the desired output,
we can then reverse it to get the final answer
stack is a good tool for reversing. hence we store the answer initially
in a stack and then keep popping off from top to fill the answer vector
now, if we traverse the array in reverse, the method becomes obvious
we use a stack to store the nodes while traversing the tree
for any node (already in the stack), we pop it off and add the value to
the answer stack. now we add the children in the left to right order
and repeat the process... essentially we are adding values to the node stack
in the order root, left, right while the answer stack received values in
the order root->right->left whose reverse is left right root which is output 
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL){return vector<int>(0,0);}
        vector<int> ans; stack<int> ans1;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            auto n = s.top(); s.pop();
            ans1.push(n->val);
            for(int i=0; i<n->children.size(); i++){
                if(n->children[i] != NULL){
                    s.push(n->children[i]);
                }
            }
        }
        while(!ans1.empty()){
            ans.push_back(ans1.top()); ans1.pop();
        }
        return ans;
    }
};