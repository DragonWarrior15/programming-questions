/*
selection sort algorithm
Consider an Array a of size N
Iterate from 1 to N
In iteration select the minimum and swap it with

Problem
You are given an array a, size of the array N and an integer x. 
Follow the above algorithm and print the state of the array after 
x iterations have been performed.

Input Format
The first line contains two integer N and x denoting the size of the 
array and the steps of the above algorithm to be performed respectively. 
The next line contains N space separated integers denoting the elements of the array.

Output Format
Print N space separated integers denoting the state of the array after x steps

Constraints
1 <= N <= 100
1 <= a[i] <= 100
1 <= x <= N

SAMPLE INPUT
5 2
1 2 3 4 5

SAMPLE OUTPUT
1 2 3 4 5
*/

#include <iostream>
using namespace std;

int main(){
    int N, x, i, j, tmp, min_index;
    cin >> N >> x;
    int a[N];
    for(i=0; i<N; i++){
        cin >> a[i];
    }
    for(i=0; i<x; i++){
        // perform the min finding iteration x times
        min_index = i;
        for(j=i+1; j<N; j++){
            // can skip first i elements as they are already sorted
            if(a[j] < a[min_index]){min_index = j;}
        }
        // swap min index with i
        tmp = a[i]; a[i] = a[min_index]; a[min_index] = tmp;
    }
    for(i=0; i<N; i++){
        cout << a[i] << " ";
    }cout << endl;
    return 0;
}
