/*
Given a string S, and two numbers N, M - arrange the characters of string 
in between the indexes N and M (both inclusive) in descending order. (Indexing starts from 0).

Input Format:
First line contains T - number of test cases.
Next T lines contains a string(S) and two numbers(N, M) separated by spaces.

Output Format:
Print the modified string for each test case in new line.

Constraints:
1 <= T <= 1000
1 <= |S| <= 10000 ;|S| denotes the length of string.
0 <= N <= M < |S|
S in [a,z]
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T, i, j, k, N, M; char t;
    cin >> T;
    for(i=0; i<T; i++){
        char S[10000];
        cin >> S >> N >> M;
        /*
        for(j=N; j<=M; j++){
            for(k=j+1; k<=M; k++){
                if(S[j] < S[k]){
                    t = S[j]; S[j] = S[k]; S[k] = t;
                }
            }
        }
        */
        sort(S+N,S+M+1,greater<char>());
        cout << S << endl;
    }
    return 0;
}
