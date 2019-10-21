/*
Given a 2D array A, your task is to convert all rows to columns and columns to rows.

Input:
First line contains 2 space separated integers, N - total rows, M - total columns.
Each of the next N lines will contain M space separated integers.

Output:
Print M lines each containing N space separated integers.

Constraints:
1 <= N <= 10
1 <= M <= 10
0 <= A[i][j] <= 100
*/

#include <iostream>
using namespace std;

int main(){
    int N, M, i, j;
    cin >> N >> M;
    int A[N][M];
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            cout << A[j][i] << " ";
        }cout << endl;
    }
    return 0;
}