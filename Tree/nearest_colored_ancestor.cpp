#include<iostream>
using namespace std;
long tree_par[100001];
long color[100001];
int main(){
  long n, c, i, root, par;
  scanf(" %ld", &n);
  scanf(" %ld", &c);
  i = 1;
  root = 1;
  tree_par[1] = 0;
  while(i <= n - 1){
    scanf(" %ld",&par);
    tree_par[i + 1] = par;
    i++;
  }
  i = 1;
  while(i <= n){
    //par here is the color
    scanf(" %ld", &par);
    color[i] = par;
    i++;
  }
  cout<<"-1 ";
  i = 2;
  long node;
  int found;
  while(i <= n){
    found = 0;
    node = tree_par[i];
    while(found != 1 && node != 0){
      if(color[node] == color[i]){
        cout<<node<<" ";
        found = 1;
      }else{
        node = tree_par[node];
      }
    }
    if (found == 0){
      cout<<"-1 ";
    }
    i++;
  }
  return 0;
}