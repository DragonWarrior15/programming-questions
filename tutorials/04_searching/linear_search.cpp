/*
You have been given an array of size N consisting of integers. In addition 
you have been given an element M you need to find and print the index of 
the last occurrence of this element M in the array if it exists in it, 
otherwise print -1. Consider this array to be 1 indexed.

Input Format:
The first line consists of 2 integers N and M denoting the size of the 
array and the element to be searched for in the array respectively. The 
next line contains N space separated integers denoting the elements of the 
array.

Output Format
Print a single integer denoting the index of the last occurrence of 
integer M in the array if it exists, otherwise print -1.

Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= M <= 10^9
*/

#include <iostream>
using namespace std;

int main(){
    long long N, M, i, index = -1; cin >> N >> M; long long A[N];
    for(i=0; i<N; i++){cin >> A[i];}
    for(i=0; i<N; i++){
        if(A[i] == M){
            index = i+1;
        }
    }cout << index << endl;
    return 0;
}
