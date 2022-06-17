/*
A left rotation operation on an array of size n shifts each of the array's 
elements 1 unit to the left. For example, if 2 left rotations are performed on 
array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2].
Given an array of n integers and a number d, perform d left rotations on the array. 
Then print the updated array as a single line of space-separated integers.

Input Format
The first line contains two space-separated integers denoting the respective values of
n (the number of integers) and e (the number of left rotations you must perform).
The second line contains n space-separated integers describing the respective 
elements of the array's initial state.

Constraints
1 <= n <= 10**5
1 <= d <= n
1 <= ai <= 10**6

Output Format
Print a single line of n space-separated integers denoting the final state of the 
array after performing d left rotations.

Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4

Explanation
When we perform 4 left rotations, the array undergoes the following sequence of changes:
12345 -> 23451 -> 34512 -> 45123 -> 51234
Thus, we print the array's final state as a single line of space-separated values, 
which is 5 1 2 3 4.
*/

/*
an int at index i, will be at position (i - d)%n
after d left rotations, doing the reverse, an element
at index i after d rotations, was initially at index
i+d or i+d-n, whichever is less than n and more than 0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read data
    int n, d; cin >> n; cin >> d;
    int a[n], i; for(i = 0; i < n; i++){cin >> a[i];}
    // logic
    for(i = 0; i < n; i++){
        if(0 <= i + d and i + d <= n - 1){
            cout << a[i + d] << " ";
        }else{
            cout << a[i + d - n] << " ";
        }
    }cout << endl;
}
