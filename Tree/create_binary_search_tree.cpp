#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
struct node{
  int data;            //Data element
  struct node* left;  //Pointer to left node
  struct node* right; //Pointer to right node
};
struct node* newNode(int element){
  struct node* temp=(node* )malloc(sizeof(struct node));
  temp->data=element;
  temp->left=temp->right=NULL;
  return temp;
}
struct node* insert(struct node* root, int data){
  if (root == NULL)    //If the tree is empty, return a new,single node
    return newNode(data);
  else{
    //Otherwise, recur down the tree 
    if (data <= root->data)
      root->left  = insert(root->left, data);
    else
      root->right = insert(root->right, data);
    //return the (unchanged) root pointer 
    return root;
  }
}
struct node* binary_tree_search(struct node* root, int element){
  while (root->data != element){
    if (element < root->data){
      root = root->left;
    }else{
      root = root->right;
    }
  }
  return root;
}
// int binary_tree_search(struct node* root, long element){
//   while (root != NULL){
//     if (element < root->data){
//       root = root->left;
//     }else if (element == root -> data){
//       return 1;
//     }else{
//       root = root->right;
//     }
//   }
//   return 0;
// }
void pre_order(struct node* root){
  cout<<root->data<<"\n";
  if(root->left != NULL) pre_order(root->left);
  if(root->right != NULL) pre_order(root->right);
  return;
}
int maxDepth(struct node* node) {
  if (node==NULL) 
      return 0;
  else{
    /* compute the depth of each subtree */
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    /* use the larger one */
    if (lDepth > rDepth) 
          return(lDepth + 1);
    else 
         return(rDepth + 1);
  }
} 
int main(){
  int N, A;
  scanf(" %d", &N);
  struct node* root;
  root = (struct node*)malloc(sizeof(struct node));
  root = NULL;
  while(N--){
    scanf(" %d", &A);
    root = insert(root, A);
  }
  // pre_order(binary_tree_search(root, Q));
  cout<<maxDepth(root);
  return 0;
}
