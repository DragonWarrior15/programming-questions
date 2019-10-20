/*
Given a chess board having N x N cells, you need to place N queens on the board in 
such a way that no queen attacks any other queen.

Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, 
then print "YES" (without quotes) in first line, then print N lines having N integers. The integer 
in ith line and jth column will denote the cell of the board and should be 1 if a queen is placed
otherwise 0. If there are more than way of placing queens print any of them.

If it is not possible to place all N queens in the desired way, then print "NO" (without quotes).

Constraints:
1 <= N <= 10
*/
#include <iostream>
using namespace std;
int main(){
    int N, i, j, placed, row, col;
    bool collision = false;
    cin >> N;
    int board[N][N];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            board[i][j] = 0;
        }
    }
    if(N==1){cout << "YES" << endl << "1" << endl;}
    else{
        // start with the first cell then keep incrementing
        row=0; col=0; placed = 0;
        while(1){
            // cout << row << " " << col << " " << placed << endl;
            if(placed == N){
                // all queens placed, print and break the loop
                cout << "YES" << endl;
                for(i=0; i<N; i++){
                    for(j=0; j<N; j++){
                        cout << board[i][j] << " ";
                    }cout << endl;
                }break;
            }else if(col == N && row == -1){
                // backtracking exhausted, print no and break
                cout << "NO" << endl; break;
            }else if(col == N){
                // backtrack to the previous 1
                placed -= 1; row -= 1;
                for(i=0; i<N; i++){
                    if(board[row][i] == 1){
                        col = i+1; board[row][i] = 0; break;
                    }
                }
            }else if(board[row][col] != 1){
                // try to find the next position for placing 1
                collision = false;
                for(i=0; i<N; i++){
                    if(board[row][i] == 1 | board[i][col] == 1){
                        // not possible to place in this position, move on
                        collision = true;
                    }
                    if(row+i < N && col+i < N){
                        if(board[row+i][col+i] == 1){collision = true;}
                    }
                    if(row+i < N && 0 <= col-i){
                        if(board[row+i][col-i] == 1){collision = true;}
                    }
                    if(0 <= row-i && col+i < N){
                        if(board[row-i][col+i] == 1){collision = true;}
                    }
                    if(0 <= row-i && 0 <= col-i){
                        if(board[row-i][col-i] == 1){collision = true;}
                    }

                    if(collision){col += 1; break;}
                }if(collision){continue;}
                board[row][col] = 1;
                row += 1; col = 0;
                placed += 1;
            }else{continue;}
        }
    }
    return 0;
}
