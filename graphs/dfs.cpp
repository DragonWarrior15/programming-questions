#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
  int N, a, b, i, x, marker[100001], ans = 0;
  stack<int> s;
  vector<int> adjList[100001];
  vector<int>::const_iterator cii;
  std::fill(marker, marker + 100001, 0);
  scanf(" %d", &N);
  scanf(" %d", &M);
  i = M;
  while(i--){
    scanf("%d", &a);
    scanf("%d", &b);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  scanf("%d", &x);
  s.push(x);
  while(!s.empty()){
    i = s.top();
    s.pop();
    marker[i] = 1;
    for (cii = adjList[i].begin(); cii != adjList[i].end(); cii++){
      if(!marker[*cii]){
        s.push(*cii);
      }
    }
  }
  // no of nodes not connected to x
  for (i = 0; i < 100001; ++i){
    if(marker[i]){ans++;}
  }
  cout<<M - ans;
  return 0;
}
