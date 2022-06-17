/*
You will be given an array of integers and a target value. Determine the 
number of pairs of array elements that have a difference equal to a 
target value.
For example, given an array of [1, 2, 3, 4] and a target value of 1, we 
have three values meeting the condition: [1,2], [2,3], and [3,4].

Input Format
The first line contains two space-separated integers n and k, the size 
of array a and the target value.
The second line contains n space-separated integers of the array a.

Constraints
2 <= n <= 10**5
0 < k < 10**9
0 < a[i] < 2**31 - 1
each integer a[i] will be unique

Output Format
An integer representing the number of pairs of integers whose difference is k.

Sample Input
5 2  
1 5 3 4 2  

Sample Output
3

Explanation
There are 3 pairs of integers in the set with a difference of 2: 
[5,3], [4,2] and [3,1] .
*/

/*
after sorting the array, use two pointers to track the pairs
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    long long n, k, count = 0;
    cin >> n >> k;
    long long a[n], i, j;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    // sort array
    sort(a, a + sizeof(a)/sizeof(a[0]));
    // logic, use two pointers to track pairs of numbers
    i = n - 1;
    j = i - 1;
    // look for a matching j for the i
    while(j >= 0){
        // the loop continues till either a match is obtained or the 
        // difference becomes more than k
        if(a[i] - a[j] > k){
            // difference is more than k, no need to check further
            // reset i
            i--;
        }else if(a[i] - a[j] == k){
            // a pair is found, reset i and j
            count++;
            i--; j--;
        }else{
            // go more left to check
            j--;
        }
    }
    cout << count << endl;
    return 0;
}
