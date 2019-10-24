/*
You have been given an array A consisting of N integers. All the elements 
in this array A are unique. You have to answer some queries based on the 
elements of this array. Each query will consist of a single integer x. 
You need to print the rank based position of this element in this array 
considering that the array is 1 indexed. The rank based position of an 
element in an array is its position in the array when the array has been 
sorted in ascending order.
Note: It is guaranteed that all the elements in this array are unique 
and for each x belonging to a query, value x shall exist in the array

Input Format
The first line consists of a single integer N denoting the size of array A.
 The next line contains N unique integers, denoting the content of array A. 
 The next line contains a single integer q denoting the number of queries.
  Each of the next q lines contains a single integer x denoting the element 
  whose rank based position needs to be printed.

Output Format
You need to print q integers denoting the answer to each query.

Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= q <= 10^5
1 <= x <= 10^9

*/
/*
Binary search
If the array is sorted, we can use this method which reduces the 
area to look by half at each step. It takes the mid point, and checks
if the number to look for is higher or lower.. using this check, we 
have already identified which half of the array will the number be in
then we can recursively keep doing this search on the halved array
*/

#include <iostream>
using namespace std;
void quicksort(long long *arr, long long start, long long end, 
               long long size);
long long binary_search(long long *arr, long long num, 
                        long long start, long long end);
int main(){
    // read all the inputs
    long long N, q; cin >> N; long long A[N], i, idx;
    for(i=0; i<N; i++){cin >> A[i];}
    cin >> q; long long query[q];
    for(i=0; i<q; i++){cin >> query[i];}
    // sort the array
    quicksort(A, 0, N, N);
    // do binary search for each of the queries
    for(i=0; i<q; i++){
        idx = binary_search(A, query[i], 0, N);
        cout << idx + 1 << endl;
    }
    return 0;
}

// function for binary search
long long binary_search(long long *arr, long long num, 
                        long long start, long long end){
    long long mid;
    while(1){
        mid = (start + end)/2;
        if(start + 1 == end){
            if(arr[start] == num){
                return start;
            }else if(arr[end] == num){
                return end;
            }else{
                // number not found
                return -1;
            }
        }else if(arr[mid] == num){
            return mid;
        }else if(arr[mid] < num){
            // num in bottom half
            start = mid+1;
        }else{
            // num in top half
            end = mid-1;
        }
    }
}

// sort the array first before applying binary search
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
