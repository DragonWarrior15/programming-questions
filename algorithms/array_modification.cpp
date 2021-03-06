/*
Starting with a 1-indexed array of zeros and a list of operations, 
for each operation add a value to each of the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in your array.

For example, the length of your array of zeros n=10. Your list of queries is as follows:
    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of k between the indices a and b inclusive:
index->  1 2 3  4  5 6 7 8 9 10
        [0,0,0, 0, 0,0,0,0,0, 0]
        [3,3,3, 3, 3,0,0,0,0, 0]
        [3,3,3,10,10,7,7,7,0, 0]
        [3,3,3,10,10,8,8,8,1, 0]

The largest value is 10 after all operations are performed.

Input Format
The first line contains two space-separated integers n and m,
the size of the array and the number of operations.
Each of the next lines contains three space-separated integers a, b, k,
the left index, right index and summand.

Constraints
3 <= n <= 10**7
1 <= m <= 2*(10**5)
1 <= a <= b <= n
0 <= k <= 10**9

Output Format
Return the integer maximum value in the finished array.

Sample Input
5 3
1 2 100
2 5 100
3 4 100

Sample Output
200

Explanation

After the first update list will be 100 100 0 0 0.
After the second update list will be 100 200 100 100 100.
After the third update list will be 100 200 200 200 100.
The required answer will be 200.
*/

/*
this can be solved in linear time with prefix sums
we create an array of 0s and use the query to update the array
suppose k is to be added between indices a and b, and we just update the
array to add k at index a and subtract b and index b. Now if we calculate
the prefix sum, it is 0 for all indices < a, k for indices a to b, and again 0
for indices > b (prefix sum arr[i] = sum(arr[0:i-1]))

hence, the exercise is simply to update indices in above fashion,
then calculate prefix sum in O(n) keeping track of max
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m; cin >> n >> m;
    long long i, a, b, k;
    vector<pair<long long, long long>>arr;
    while(m--){
        // read the queries
        cin >> a >> b >> k;
        // increment lower by k and decrease upper by k
        arr.push_back(make_pair(a, k));
        arr.push_back(make_pair(b + 1, -k));
    }
    // sort the indices
    sort(arr.begin(), arr.end());
    // calculate prefix sums
    long long max_val = 0, sum = 0;
    vector<pair<long long, long long>>::iterator itr;
    for(itr = arr.begin(); itr != arr.end(); itr++){
        sum += itr->second;
        max_val = max(max_val, sum);
    }
    cout << max_val << endl;
    return 0;
}
