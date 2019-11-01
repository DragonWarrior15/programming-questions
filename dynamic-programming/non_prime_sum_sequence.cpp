/*
Every lock sequence in hogwarts is a sequence of length N and contains 
digits from 0 - 9 . Now there is a constraint that each lock sequence 
will not contain two adjacent numbers such that they sum up to a prime number.

For example 9994 is an invalid sequence of lock because 9+4 = 13 but 13 is 
a prime number. 9993 is a valid sequence of lock beacuse there are no two 
adjacent numbers such that theys sum up to a prime number.

So for the given length N you have to count total possible lock sequences modulo 10^9+7

Input
First line contains a number N as input

Output
Output total locks possible as per the given constraints

Constraints
1≤ N ≤ 105
SAMPLE INPUT
2
SAMPLE OUTPUT
63
Explanation
There are 63 locks possible . 00 is also a valid lock sequence.
*/

/*
The logic we use is based on dynamic programming, assuming we know the count of
possible sequences of length N-1 broken down by which digit they end in, then 
for count of sequences of length N, we calculate count of sequence of length N
ending in digits 0, 1, .. 9. The required answer is then N0 + .. + N9.
for each ending digit, we know the list of digits that are possible before that
below, and this way, we can recursively calculate the required answer.
0 -> 1 4 6 8 9
1 -> 0 3 5 7 8 9
2 -> 2 4 6 7 8
3 -> 1 3 5 6 7 9
4 -> 0 2 4 5 6 8
5 -> 1 3 4 5 7 9
6 -> 0 2 3 4 6 8 9
7 -> 1 2 3 5 7 8 9
8 -> 0 1 2 4 6 7 8
9 -> 0 1 3 5 6 7 9
*/

#include <iostream>
using namespace std;

const long long divide_by = 1000000007;

int main(){
    // read the data
    long long N; cin >> N;
    // array to store sequential data
    long long A[N][10], i, j, ans=0;
    for(i=0; i<10; i++){
        A[0][i] = 1;
    }
    // A[0][2] = 0; A[0][3] = 0; A[0][5] = 0; A[0][7] = 0;
    for(i=1; i<N; i++){
        for(j=0; j<10; j++){
            if(j==0){
                A[i][j] = A[i-1][0] + A[i-1][1] + A[i-1][4] + A[i-1][6] + A[i-1][8] + A[i-1][9];
            }else if(j==1){
                A[i][j] = A[i-1][0] + A[i-1][3] + A[i-1][5] + A[i-1][7] + A[i-1][8] + A[i-1][9];
            }else if(j==2){
                A[i][j] = A[i-1][2] + A[i-1][4] + A[i-1][6] + A[i-1][7] + A[i-1][8];
            }else if(j==3){
                A[i][j] = A[i-1][1] + A[i-1][3] + A[i-1][5] + A[i-1][6] + A[i-1][7] + A[i-1][9];
            }else if(j==4){
                A[i][j] = A[i-1][0] + A[i-1][2] + A[i-1][4] + A[i-1][5] + A[i-1][6] + A[i-1][8];
            }else if(j==5){
                A[i][j] = A[i-1][1] + A[i-1][3] + A[i-1][4] + A[i-1][5] + A[i-1][7] + A[i-1][9];
            }else if(j==6){
                A[i][j] = A[i-1][0] + A[i-1][2] + A[i-1][3] + A[i-1][4] + A[i-1][6] + A[i-1][8] + A[i-1][9];
            }else if(j==7){
                A[i][j] = A[i-1][1] + A[i-1][2] + A[i-1][3] + A[i-1][5] + A[i-1][7] + A[i-1][8] + A[i-1][9];
            }else if(j==8){
                A[i][j] = A[i-1][0] + A[i-1][1] + A[i-1][2] + A[i-1][4] + A[i-1][6] + A[i-1][7] + A[i-1][8];
            }else{
                A[i][j] = A[i-1][0] + A[i-1][1] + A[i-1][3] + A[i-1][5] + A[i-1][6] + A[i-1][7] + A[i-1][9];
            }
            A[i][j] %= divide_by;
        }
    }
    for(i=0; i<10; i++){
        ans += A[N-1][i];
    }
    cout << ans % divide_by << endl;
    return 0;
}