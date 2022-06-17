/*
Alice is a kindergarten teacher. She wants to give some candies to the 
children in her class. All the children sit in a line and each of them has 
a rating score according to his or her performance in the class. 
Alice wants to give at least 1 candy to each child. If two children sit 
next to each other, then the one with the higher rating must get more candies. 
Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. 
She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. 
She must buy a minimum of 10 candies.

Input Format
The first line contains an integer n the number of students.
Each of the next lines contains an integer indicating the rating of 
the student at position i.

Constraints
1 <= n <= 10**5
1 <= a[i] <= 10**5

Output Format
Output a single line containing the minimum number of candies Alice must buy.

Sample Input 0
3
1
2
2

Sample Output 0
4

Explanation 0
Here 1, 2, 2 is the rating. Note that when two children have equal rating, 
they are allowed to have different number of candies. 
Hence optimal distribution will be 1, 2, 1.

Sample Input 1
10
2
4
2
6
1
7
8
9
2
1

Sample Output 1
19

Explanation 1
Optimal distribution will be 1, 2, 1, 2, 1, 2, 3, 4, 2, 1

Sample Input 2
8
2
4
3
5
2
6
4
5

Sample Output 2
12

Explanation 2
Optimal distribution will be 1, 2, 1, 2, 1, 2, 1, 2
*/

/*
To find the minimum number of candies, we must find sequences of increasing
and decreasing ranks within the given array. Assign all the children a candy of
1 and start going right. If we encounter a higher rank, clearly the number of
candies for that child should be at least 1 + candies of left child.
If we do the same for the reverse of the array, we can work through the same
logic but for decreasing ranks (since increasing ranks going left is same as
decreasing ranks going right). But, we must be careful that the new assigned
value in second pass should not be less than the already assigned value
example : 1 2 3 4 1 in rightwards pass, candies become 1 2 3 4 1
if we do not take max, the candies will become 1 2 3 2 1 which is incorrect
with the max logic, the candies will be 1 2 3 4 1.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    unsigned int n, i, k; cin >> n;
    unsigned long long total_candies = 0;
    unsigned int a[n], c[n], distinct_count = 0, count = 0;
    short int slope = 0;
    // keep track of the longest increasing or decreasing sequence
    // of ranks since the max no of candies will not exceed this
    for(i = 0; i < n; i++){
        cin >> a[i]; 
        c[i] = 1;
    }
    // logic
    for(i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            c[i] = c[i - 1] + 1;
        }
    }
    for(i = 1; i < n; i++){
        k = n - i;
        if(a[k - 1] > a[k]){
            if(c[k - 1] < c[k] + 1){
                c[k - 1] = c[k] + 1;
            }
        }
    }
    // get sum
    for(i = 0; i < n; i++){
        total_candies += c[i];
    }
    cout << total_candies << endl;
    return 0;
}
