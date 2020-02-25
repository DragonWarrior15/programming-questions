/*
You are working at the cash counter at a fun-fair, and you have different types
of coins available to you in infinite quantities. The value of each coin is 
already given. Can you determine the number of ways of making change for a 
particular number of units using the given types of coins?

For example, if you have 4 types of coins, and the value of each type is given as 
8, 3, 1, 2 respectively, you can make change for 3 units in three ways:
{1, 1, 1} , {1, 2}, and {3}.

Input Format

The first line contains two space-separated integers describing the respective 
values of n and m where n is the number of units mis the number of coin types.
The second line contains space-separated integers describing the respective values
of each coin type c[i].

Constraints
Each c[i] is guaranteed to be distinct.
1 <= c[i] <= 50
1 <= n <= 250
1 <= m <= 50

Hints
Solve overlapping subproblems using Dynamic Programming (DP):
You can solve this problem recursively but will not pass all the test cases 
without optimizing to eliminate the overlapping subproblems. Think of a way 
to store and reference previously computed solutions to avoid solving the 
same subproblem multiple times. * Consider the degenerate cases:
- How many ways can you make change for
cents? - How many ways can you make change for cents if you have no coins? 
* If you're having trouble defining your solutions store, then think 
about it in terms of the base case when units is 0. 
- The answer may be larger than a 32-bit integer.

Output Format
Print a long integer denoting the number of ways we can get a sum of n
from the given infinite supply of m types of coins.

Sample Input 0
4 3
1 2 3

Sample Output 0
4

Explanation 0
There are four ways to make change for using coins with values given by
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}

Sample Input 1
10 4
2 5 3 6

Sample Output 1
5

Explanation 1
There are five ways to make change for units using coins with values given by
{2, 2, 2, 2, 2}
{2, 2, 6}
{2, 2, 3, 3}
{2, 5, 3}
{5, 5}
*/

/*
a simple recursion will not execute within time limits
hence we maintain an array of any visited states so that
the same number can be reused in any future calculations
*/

#include <bits/stdc++.h>
using namespace std;

int g_visited[50][251];
long long g_ways[50][251];

long long count_ways(int *arr, int tot_coins, int idx, int change);

int main(){
    // read the data
    int n, m, i, j; int count;
    cin >> n >> m;
    int c[m];
    for(i = 0; i < m; i++){
        cin >> c[i];
    }
    for(i = 0; i < 50; i++){
        for(j = 0; j < 251; j++){
            g_visited[i][j] = 0;
            g_ways[i][j] = 0;
        }
    }
    cout << count_ways(c, m, 0, n) << endl;
    return 0;
}

long long count_ways(int *arr, int tot_coins, int idx, int change){
    // terminal conditions
    if(idx == tot_coins){
        // all indices exhausted
        if(change == 0){
            // if change is also exhausted
            return 1;
        }else{
            // change not exhausted hence this configuration not allowed
            return 0;
        }
    }else if(change < 0){
        // reached negative change
        return 0;
    }
    else if(g_visited[idx][change]){
        // check if state has already been visited
        return g_ways[idx][change];
    }else{
        long long count = 0;
        // mark the state visited and calculate its value
        g_visited[idx][change] = 1;
        // recursion
        // either take one coin of current index, or move to the next
        // index without taking any coins
        count = count_ways(arr, tot_coins, idx, change - arr[idx]) + 
                count_ways(arr, tot_coins, idx + 1, change);      
        g_ways[idx][change] = count;
        return count;
    }
    return 0;
}
