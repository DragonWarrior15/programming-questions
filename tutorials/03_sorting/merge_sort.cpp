/*
Given an array A on size N, you need to find the number of ordered pairs (i, j)
such that i < j and A[i] > A[j]

Input:
First line contains one integer, N, size of array.
Second line contains N space separated integers denoting the 
elements of the array A.

Output:
Print the number of ordered pairs described above

Constraints:
1 <= N <= 10^6
1 <= A[i] <= 10^6
*/

#include <iostream>
using namespace std;

int main(){
    int N, i, j, count = 0; cin >> N; int A[N];
    for(i=0; i<N; i++){cin >> A[i];}
    
    return 0;
}

void merge()