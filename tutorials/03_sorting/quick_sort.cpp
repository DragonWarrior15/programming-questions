/*
You have been given an array A of size N. This array contains large integers
ranging from 1 to 10^9. You need to sort the contents of this array by their 
value and then print the contents of it.

Input Format:
The first line contains a single integers N denoting the size of the array. 
The next line contains N space separated integers denoting the contents of the array.

Output Format:
Print N space separated integers, i.e. the final sorted array.

Constraints:
1 <= N <= 10^6
1 <= A[i] <= 10^9
*/

/*
quicksort selects a random element as pivot, gets it to the correct position
with smaller elements on left and larger elements on right, and then applies
quicksort recursively on either side
*/

#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

void quicksort(long long *arr, long long start, long long end, long long size){
    // perform quicksort on a given array
    // check the base case of length 1 or 2
    if(end - start == 1 | end == start){
        ;
    }else if(end - start == 2){
        if(arr[start] > arr[end-1]){
            long long tmp = arr[start]; arr[start] = arr[end-1]; arr[end-1] = tmp;
        }
    }else{
        // select a random pivot element first
        long long pivot = start + rand()%(end-start); long long tmp, i, j;
        // put the pivot at the start of array
        tmp = arr[start]; arr[start] = arr[pivot]; arr[pivot] = tmp;
        // sort the array such that smaller elements are on left
        // side and vice versa
        j = start+1;
        for(i=start+1; i<end; i++){
            if(arr[i] < arr[start]){
                tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                j++;
            }
        }
        // new pivot is at j-1
        tmp = arr[start]; arr[start] = arr[j-1]; arr[j-1] = tmp;
        // perform quicksort on either side
        quicksort(arr, start, j-1, size);
        quicksort(arr, j, end, size);
    }
}

int main(){
    // read the input
    long long N; cin >> N; long long A[N], i;
    for(i=0; i<N; i++){cin >> A[i];}
    // perform quick sort
    quicksort(A, 0, N, N);
    // write the output
    for(i=0; i<N; i++){cout << A[i] << " ";}cout << endl;
    return 0;
}
