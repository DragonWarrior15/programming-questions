/*
bubble sort
repeatedly compare adjacent elements and switch their positions as needed
two for loop over the size of array are used to achieve this

You have been given an array A of size N . you need to sort this array 
non-decreasing order using bubble sort. However, you do not need to print 
the sorted array. You just need to print the number of swaps required 
to sort this array using bubble sort

Input Format
The first line consists of a single integer N denoting size of the array. 
The next line contains N space separated integers denoting the elements of the array.

Output Format
Print the required answer in a single line

Constrains
1 <= N <= 100
1 <= a[i] <= 100
*/

#include <iostream>
using namespace std;

int main(){
    int N, i, j, swaps = 0, tmp;
    cin >> N;
    int a[N];
    for(i=0; i<N; i++){cin >> a[i];}
    // bubble sort
    for(i=0; i<N; i++){
        for(j=0; j<N-1; j++){
            if(a[j] > a[j+1]){
                // swap
                swaps += 1;
                tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;
            }
        }
    }
    cout << swaps << endl;
    return 0;
}
