/*
You have been given an integer array A of size N. Each element of the array 
ranges between 1 and 10^5. You need to find the frequency of each distinct
element of the array. The elements need to be present in the output in 
ascending order. You need to print the value and then frequency of each 
distinct element.

Input Format:
The first line contains a single integer N denoting the size of the array. 
The next line contains N space separated integers, denoting the elements 
of the array.

Output Format
For each distinct integer, print its value and then frequency in a new line. 
The distinct integers should appear in the output in ascending order.

Constraints
1 <= N <= 100
1 <= A[i] <= 100
*/

/*
Counting sort
uses an auxilliary array, where the index i represents element i in the
original array, and value represents the frequency. To get the final
sorted list, traverse this new array from left to right for ascending order
*/

#include <iostream>
using namespace std;

int main(){
    int N, size=101; cin >> N; int A[N], Aux[size], i;
    // read the array to be sorted
    for(i=0; i<N; i++){cin >> A[i];}
    // initialize the aux array with zeros
    for(i=0; i<size; i++){Aux[i] = 0;}
    // get the frequency
    for(i=0; i<N; i++){
        Aux[A[i]]++;
    }
    // print the output
    for(i=0; i<size; i++){
        if(Aux[i] != 0){
            cout << i << " " << Aux[i] << endl;
        }
    }
    return 0;
}