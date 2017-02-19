#include <iostream>
#include <queue>
using namespace std;

int main(){
  int N, M, i, j, e, planet[1001][1001], exists[1001][1001], x, y, num_nations;
  queue<int> x_corr;
  queue<int> y_corr;
  long Q;
  scanf(" %d", &N);
  scanf(" %d", &M);
  scanf(" %ld", &Q);
  i = N; j = M, num_nations = 0;
  for (i = 1; i <= N; i++){
    for (j = 1; j <= M; j++){
      scanf(" %d", &e);
      planet[i][j] = e;
      if (e){exists[i][j] = 1; num_nations++;}else{exists[i][j] = 0;}
    }
  }
  while(Q--){
    scanf(" %d", &x);
    scanf(" %d", &y);
    if (planet[x][y] == 0){
      printf("%d\n", num_nations);
    }
    else{
      x_corr.push(x);
      y_corr.push(y);
      while(!x_corr.empty()){
        x = x_corr.front(); x_corr.pop();
        y = y_corr.front(); y_corr.pop();
        if (exists[x][y]){
          exists[x][y] = 0;
          num_nations--;
          if (exists[(x - 1) + int(x == 1)][y]){x_corr.push((x - 1) + int(x == 1)); y_corr.push(y);}
          if (exists[(x + 1) - int(x == N)][y]){x_corr.push((x + 1) - int(x == N)); y_corr.push(y);}
          if (exists[x][(y - 1) + int(y == 1)]){x_corr.push(x); y_corr.push((y - 1) + int(y == 1));}
          if (exists[x][(y + 1) - int(y == M)]){x_corr.push(x); y_corr.push((y + 1) - int(y == M));}
        }
      }
      printf("%d\n", num_nations);
    }
  }
  return 0;
}
