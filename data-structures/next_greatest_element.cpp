/*
Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on 
the right side of x in array. Elements for which no greater element exist, 
consider next greater element as -1.

For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element --> NGE
4 --> 5
5 --> 25
2 --> 25
25 --> -1

For the input array [13, 7, 6, 12}, the next greater elements for each 
element are as follows.
Element --> NGE
13 --> -1
7 --> 12
6 --> 12
12 --> -1

Input Format

The first line of input contains an integer n denoting the size of the array
The next line contains n space seperated array elements in integer range
0 < n < = 65535

Output Format
Output consists of n lines
Each line should contain 2 space seperated integers
The first integer should represent the array element and second integer should 
represent the next greater element

Sample Input
4
4 5 2 25

Sample Output
4 5
5 25
2 25
25 -1
*/

/*
the problem of next biggest element is solvable in O(n) via a stack
simply keep adding elements on a stack till they are less than of equal
to the top most element. when we arrive at a larger element, pop those elements
that are smaller than this element. For all the popped elements, the current
number was the largest next elements. continue this till the end of array
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    int n; cin >> n;
    int a[n], i, nge[n];
    for(i = 0; i < n; i++){cin >> a[i]; nge[i] = -1;}
    // logic, use a stack to get the next biggest element
    stack<int> s;
    i = 0;
    while(i < n){
        if(s.empty()){
            // push to stack top
            s.push(i);
            i++;
        }else{
            // compare with top
            if(a[i] <= a[s.top()]){
                // add to stack as smaller
                // cout << s.top() << " b " << i << endl;
                s.push(i);
                i++;
            }else{
                // next greater element observed for some
                // cout << s.top() << " a " << i << endl;
                nge[s.top()] = a[i];
                s.pop();
            }
        }
    }
    // output the elements
    for(i = 0; i < n; i++){
        cout << a[i] << " " << nge[i] << endl;
    }
    return 0;
}