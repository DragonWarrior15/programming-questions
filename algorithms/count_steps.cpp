/*
Davis has a number of staircases in his house and he likes to climb 
each staircase 1, 2, or 3 steps at a time. Being a very precocious child, 
he wonders how many ways there are to reach the top of the staircase.

Given the respective heights for each of the staircases in his house, 
find and print the number of ways he can climb each staircase module on a new line.

For example, there is 1 staircase in the house that is 5 steps high. 
Davis can step on the following sequences of steps:
1 1 1 1 1
1 1 1 2
1 1 2 1 
1 2 1 1
2 1 1 1
1 2 2
2 2 1
2 1 2
1 1 3
1 3 1
3 1 1
2 3
3 2

There are 13 possible ways he can take these 5 steps. 13%(10**10 + 7) = 13

Input Format
The first line contains a single integer s the number of staircases in his house.
Each of the following s lines contains a single integer n the height of staircase.

Constraints
1 <= s <= 5
1 <= n <= 36

Output Format
For each staircase, return the number of ways Davis can climb it as an integer.

Sample Input
3
1
3
7

Sample Output
1
4
44

Explanation
Let's calculate the number of ways of climbing the first two of the Davis'
staircases:

The first staircase only has 1 step, so there is only one way for him to 
climb it (i.e., by jumping step). Thus, we print 1 on a new line.

The second staircase has 3 steps and he can climb it in any of the four following ways:
1 1 1
1 2
2 1
3
Thus, we print 4 on a new line.
*/

/*
simple recursion, but keep track of already solved problems
and store them in a separate array
*/

#include <bits/stdc++.h>
using namespace std;

long count_array[37];
long MAX = 10000000007;
long count_steps(int steps);

int main(){
    // read the data
    int n; cin >> n;
    int s[n], i; for(i = 0; i < n; i++){cin >> s[i];}
    for(i = 0; i < 36; i++){
        if(i == 0){
            count_array[i] = 0;
        }else if(i == 1){
            count_array[i] = 1;
        }else if(i == 2){
            count_array[i] = 2;
        }else if(i == 3){
            count_array[i] = 4;
        }else{
            count_array[i] = 0;
        }
    }
    // recursion
    for(i = 0; i < n; i++){
        cout << count_steps(s[i]) << endl;
    }
    return 0;
}

long count_steps(int steps){
    // steps is how many steps we have to climb
    if(steps == 0){
        return 0;
    }else if(count_array[steps]){
        return count_array[steps];
    }else{
        // value not found yet
        count_array[steps] = (count_steps(steps - 1) + count_steps(steps - 2) + count_steps(steps - 3))%MAX;
        return count_array[steps];
    }
    return 0;
}
