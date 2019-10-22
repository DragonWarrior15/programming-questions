/*
insertion sort
one element from the array is consumed to find its correct position
within the array, thus we have two for loops, second one can keep decreasing
in size as the sorted array gets larger after each iteration. We pick an element
at i, and push it into the sorted array a[0..i-1] to its correct position.

Problem
You have been given an A array consisting of N integers. All the elements 
in this array are guaranteed to be unique. For each position i in the array 
A you need to find the position a[i] should be present in, if the array 
was a sorted array. You need to find this for each i and print the 
resulting solution.

Input Format:
The first line contains a single integer N denoting the size of array A. 
The next line contains N space separated integers denoting the elements 
of array A.

Output Format:
Print N space separated integers on a single line , where the Ith integer 
denotes the position of a[i] if this array were sorted.

Constraints:
1 <= N <= 100
1 <= a[i] <= 100

SAMPLE INPUT
5
1 2 3 4 5

SAMPLE OUTPUT
1 2 3 4 5
*/

#include <iostream>
using namespace std;

int main(){
    int N, i, j, tmp, k;
    cin >> N;
    int a[N], pos[N], a_old[N];
    for(i=0; i<N; i++){
        cin >> a[i]; a_old[i] = a[i];
        pos[i] = i+1;
    }
    // insertion sort
    for(i=1; i<N; i++){
        for(j=i; j>0; j--){
            if(a[j-1] > a[j]){
                // swap and update pos array
                tmp = a[j]; a[j] = a[j-1]; a[j-1] = tmp;
            }
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(a_old[i] == a[j]){
                pos[i] = j+1; break;
            }
        }
    }
    for(i=0; i<N; i++){
        cout << pos[i] << " ";
    }cout << endl;
    return 0;
}
