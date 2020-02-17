/*
You are given an unordered array consisting of consecutive integers
[1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. 
You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array [7, 1, 3, 2, 4, 5, 6]
we perform the following steps:
i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

It took 5 swaps to sort the array.

Complete the function minimumSwaps in the editor below. It must return an integer 
representing the minimum number of swaps to sort the array.

minimumSwaps has the following parameter(s): arr: an unordered array of integers

Input Format
The first line contains an integer n the size of array.
The second line contains n space-separated integers arr[i].

Constraints
1 <= n <= 10**5
1 <= arr[i] <= n

Output Format
Return the minimum number of swaps to sort the given array.

Sample Input 0
4
4 3 1 2

Sample Output 0
3

Explanation 0

Given array [4, 3, 1, 2]

After swapping (0, 2) we get [1, 3, 4, 2]
After swapping (1, 2) we get [1, 4, 3, 2]
After swapping (1, 3) we get [1, 2, 3, 4]
So, we need a minimum of 3 swaps to sort the array in ascending order.
*/

/*
Approach 1 : use selection sort to figure out the minimum no of swaps
             this approach works, but selection sort works in O(N2)
             which is not accepted by the grader
Approach 2 : utilize the structure of problem, all the elements are from
             1 to n, so we search for cycles of misplaced elements, ie, elements
             such that at position i, element is j, then at position j element is k
             and at position k, element is i. These three elements can be swapped in
             2 swaps to sort the array. Thus, we need to identify all such cycles
             and add their length-1 values to find the minimum swaps
             we do not sort the array to find this number
*/

#include <iostream>
using namespace std;

long long count_min_swaps(long long *arr, long long n);

int main(){
    // read the data
    long long n, i; cin >> n;
    long long a[n];
    for(i=0; i<n; i++){cin >> a[i];}
    // get the minimum no of swaps
    cout << count_min_swaps(a, n) << endl;
    return 0;
}

long long count_min_swaps(long long *a, long long n){
    /*
    all elements to be swapped will be present in a cycle
    if element j is present at index i and vice versa, the two can
    be sorted in a single swap. if we increase the length of cycle
    to include 3 elements, sorting can be done in 2 swaps
    thus the required count is sum of (len - 1) of all such cycles
    */
    // an array to keep track of which indices have been visited
    long long visited[n], i, visited_total=0, count=0, idx, start_idx=0, next_idx;
    for(i=0; i<n; i++){visited[i] = 0;}
    // loop through the cycles
    while(visited_total != n){
        // find the next not visited element
        for(i=start_idx; i<n; i++){if(visited[i] == 0){idx = i; break;}}
        visited[i] = 1; visited_total += 1; start_idx = i;
        if(a[idx] == idx+1){
            // element at correct position, no swap needed
            continue;
        }else{
            while(1){
                next_idx = a[idx]-1;
                if(next_idx == start_idx){
                    // break the cycle, no need to increment
                    break;
                }else{
                    // cycle still not fully covered
                    visited[next_idx] = 1; visited_total += 1; count += 1;
                    idx = next_idx;
                }
            }
        }
    }
    return count;
}

