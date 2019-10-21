/*
Given the size and the elements of array A, print all the elements in reverse order.

Input:
First line of input contains, N - size of the array.
Following N lines, each contains one integer, i{th} element of the array i.e. A[i].

Output:
Print all the elements of the array in reverse order, each element in a new line.

Constraints:
1 <= N <= 100
0 <= A[i] <= 1000
*/

#include <iostream>
using namespace std;

int main(){
    // int A[3] = {1, 2, 3}; declares array and initializes it
    int N, i;
    cin >> N;
    int A[N];
    for(i=0; i<N; i++){
        cin >> A[i];
    }
    for(i=N-1; i>=0; i--){
        cout << A[i] << endl;
    }
    return 0;
}