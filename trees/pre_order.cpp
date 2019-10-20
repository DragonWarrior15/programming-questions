#include<iostream>
using namespace std;
long left_child[100001], right_child[100001];
void pre_order(long node){
  cout<<node<<" ";
  if (left_child[node] != 0){
    pre_order(left_child[node]);
  }
  if (right_child[node] != 0){
    pre_order(right_child[node]);
  }
  return;
}
int main(){
  long t, n, X;
  scanf(" %ld", &t);
  while(t--){
    std::fill(left_child, left_child + 100001, 0);
    std::fill(right_child, right_child + 100001, 0);
    scanf(" %ld", &n);
    while(n--){
      scanf(" %ld", &X); scanf(" %ld", &left_child[X]); scanf(" %ld", &right_child[X]);
    }
    pre_order(1);
    cout<<"\n";
  }
  return 0;
}