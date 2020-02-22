/*
Given an array of integers, find the subset of non-adjacent elements 
with the maximum sum. Calculate the sum of that subset.

For example, given an array arr = [-2, 1, 3, -4, 5] we have the 
following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8

Our maximum subset sum is 8.

Input Format
The first line contains an integer n.
The second line contains n space-separated integers arr[i].

Constraints
1 <= n <= 10**5
-10**4 <= arr[i] <= 10**4

Output Format
Return the maximum sum described in the statement.

Sample Input 0
5
3 7 4 6 5

Sample Output 0
13

Explanation 0
Our possible subsets are
[3,4,5], [3,4], [3,6], [3,5], [7,6], [7,5], [4,5]
The largest subset sum is from subset 13 from [7, 6]

Sample Input 1
5
2 1 5 8 4

Sample Output 1
11

Explanation 1
Our subsets are [2,5,4], [2,5], [2,8], [2,4], [1,8], [1,4], [5,4]
The maximum subset sum is 11 from [2,5,4]

Sample Input 2
5
3 5 -7 8 10

Sample Output 2
15

Explanation 2
Our subsets are [3,-7,10], [3,8], [3,10], [5,8], [5,10], [-7,10]
The maximum subset sum is from the fifth subset listed.
*/

/*
basic recursion solution :
at any position i, max sum = max(curr elem + max sum from remaining array (i+2 onwards), 
                                 max sum from remaining array (i+1 onwards))

DP solution
maintain two sums, incl and excl (incl means including current element and vice versa)
to update at current index i,
incl[i] = arr[i] + excl[i-1] since this is the only possible way to update 
excl[i] = max(incl[i-1], excl[i-1]) either the prev is included or not
*/

#include <bits/stdc++.h>
using namespace std;

long long get_max_sum(int *arr, int start, int end);

int main(){
    // read data
    int n, i, temp; cin >> n;
    long long sum;
    int a[n]; for(i=0; i<n; i++){cin >> a[i];}
    // get the max sum recursively
    // sum = get_max_sum(a, 0, n-1);
    // cout << sum << endl;
    // dynamic programming approach
    long long incl = a[0], excl = 0, incl_prev, excl_prev;
    for(i=1; i<n; i++){
        incl_prev = incl; excl_prev = excl;
        // update the incl value as prev excl + arr[i]
        // since that is the only possible update
        incl = a[i] + excl_prev;
        // update the excl value as the max (excluding current element,
        // and new incl value
        if(incl_prev > excl_prev){
            excl = incl_prev;
        }else{
            excl = excl_prev;
        }
    }
    if(incl > excl){
        cout << incl << endl;
    }else{
        cout << excl << endl;
    }
    return 0;
}

long long get_max_sum(int *arr, int start, int end){
    long long sum, sum1, sum2;
    if(start > end){
        return 0;
    }else if(end - start == 0){
        return arr[start];
    }else if(end - start == 1){
        // we can either include start or end or neither but not both
        if(0 > arr[start] and 0 > arr[end]){
            return 0;
        }else if(arr[start] > 0 and arr[end] < 0){
            return arr[start];
        }else if(arr[start] < 0 and arr[end] > 0){
            return arr[end];
        }else{
            if(arr[start] > arr[end]){
                return arr[start];
            }else{
                return arr[end];
            }
        }
    }else{
        // sum1 includes this element
        sum1 = arr[start] + get_max_sum(arr, start + 2, end);
        // sum 2 does not include this element
        sum2 = get_max_sum(arr, start + 1, end);
        // take the max
        if(sum1 > sum2){
            return sum1;
        }else{
            return sum2;
        }
    }
}