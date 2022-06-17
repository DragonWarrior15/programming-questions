#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int N, a, b, i, x, level[100001], marker[100001], ans = 0;
  queue<int> q;
  vector<int> adjList[100001];
  vector<int>::const_iterator cii;
  std::fill(marker, marker + 100001, 0);
  std::fill(level, level + 100001, 0);
  scanf(" %d", &N);
  i = N - 1;
  while(i--){
    scanf("%d", &a);
    scanf("%d", &b);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  scanf("%d", &x);
  q.push(1);
  level[1] = 1;
  while(!q.empty()){
    i = q.front();
    q.pop();
    marker[i] = 1;
    for (cii = adjList[i].begin(); cii != adjList[i].end(); cii++){
      if(!marker[*cii]){
        q.push(*cii);
        level[*cii] = level[i] + 1;
        if(level[*cii] == x){ans++;}
      }
    }
  }
  cout<<ans;
  return 0;
}
