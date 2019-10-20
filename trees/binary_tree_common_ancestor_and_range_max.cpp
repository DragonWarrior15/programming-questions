#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
struct node{
  long long data;            //Data element
  struct node* left;  //Pointer to left node
  struct node* right; //Pointer to right node
};
struct node* newNode(long long element){
  struct node* temp=(node* )malloc(sizeof(struct node));
  temp->data=element;
  temp->left=temp->right=NULL;
  return temp;
}
struct node* insert(struct node* root, long long data){
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
// int binary_tree_search(struct node* root, long long element){
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
long long binary_tree_search_range_max(struct node* root, long long low, long long high){
  while (root != NULL){
    if (low <= root->data and high > root->data){
      // this node is the common ancestor
      break;
    }else if (low <= root->data and high <= root->data){
      // search for the common ancestor in the left
      root = root->left;
    }else{
      // search for the common ancestor in the right half
      root = root->right;
    }
  }
  // now traverse from this root to the bigger element
  long long curr_max = root->data;
  while (root->data != high){
    if (root->data > curr_max){curr_max = root->data;}
    if (high <= root->data){
      root = root->left;
    }else{
      root = root->right;
    }
  }
  if (high > curr_max){return high;}
  return curr_max;
}
int main(){
  long long LOW, HIGH, A, N;
  scanf(" %lld", &N);
  struct node* root;
  root = (struct node*)malloc(sizeof(struct node));
  root = NULL;
  while(N--){
    scanf(" %lld", &A);
    root = insert(root, A);
  }
  scanf(" %lld", &LOW);
  scanf(" %lld", &HIGH);
  if (LOW > HIGH){
    cout<<binary_tree_search_range_max(root, HIGH, LOW);
  }else{
    cout<<binary_tree_search_range_max(root, LOW, HIGH);
  }
  return 0;
}
