/*
Skyline Real Estate Developers is planning to demolish a number of old, 
unoccupied buildings and construct a shopping mall in their place. Your 
task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. 
Each building has a height, given by h[i] where i is in[0, n-1]. If you join 
adjacent buildings, they will form a solid rectangle of area
k x min(h[i], h[i + 1], ..., h[i - k + 1])

For example, the heights array [3, 2, 3]. A rectangle of height 2 and length 3 
can be constructed within the boundaries. The area formed is 6.

Input Format
The first line contains n, the number of buildings.
The second line contains n space-separated integers, each representing 
the height of a building.

Constraints
1 <= n <= 10**5
1 <= h[i] <= 10**6

Output Format
Print a long integer representing the maximum area of rectangle formed.

Sample Input
5
1 2 3 4 5

Sample Output
9

Explanation
using the rectangles of height 3, 4 and 5
*/

/*
https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
O(n) solution utilizes a stack
the algorithm consists of 3 parts. we travel the array left to right
1) if stack is empty or h[curr] >= h[top], add curr to the stack
   idea is that till the heights are increasing, we are simply adding area
   since for any of the indices accumulated in the stack so far, the maximum
   area obtainable will be that height X total indices accumulated after
   that position
   curr++
2) if h[curr] < h[top], pop the top of the stack till a suitable place
   cant be found for the indice top
   when the pop operation is done, calculate the maximum area obtainable
   with the popped height, since the popped height is more than all the heights
   in the stack, we must just check the top index in the stack and compare
   to get the area = h[top] * (top - index of next stack element - 1)
   since this is the max area with this height
3) once curr has reached the end of heights array, we start popping off
   elements from top of stack and do something similar to step 2, since this
   is the maximum area obtainable with this height
in essence, we are keeping track of an starting index and an end index where
area = min(h[starting index], h[end index]) * (starting index - end index)
for better clarity, work through the algorithm for the case of 1 2 3 2 1 heights
*/

#include <bits/stdc++.h>
using namespace std;

int max_area(int *h, int n);

int main(){
    // read the data
    int n; cin >> n;
    int h[n], i; for(i = 0; i < n; i++){cin >> h[i];}
    // logic, greedy
    cout << max_area(h, n) << endl;
    return 0;
}

int max_area(int *h, int n){
    int i = 0, idx, area, global_max = 0; stack<int> indices;
    // add to stack
    while(i < n){
        if(indices.empty() or h[i] >= h[indices.top()]){
            // add to stack as area can grow for all left indices 
            // to this index
            indices.push(i);
            i++;
        }else{
            // pop all the greater heights
            idx = indices.top(); indices.pop();
            if(indices.empty()){
                area = (i) * h[idx];
            }else{
                area = (i - indices.top() - 1) * h[idx];
            }
            if(area > global_max){
                global_max = area;
            }
        }
    }
    // process the elements remaining in the stack
    while(!indices.empty()){
        idx = indices.top(); indices.pop();
        if(indices.empty()){
            area = (i) * h[idx];
        }else{
            area = (i - indices.top() - 1) * h[idx];
        }
        if(area > global_max){
            global_max = area;
        }        
    }
    return global_max;
}