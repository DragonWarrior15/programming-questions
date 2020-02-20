/*
HackerLand National Bank has a simple policy for warning clients 
about possible fraudulent account activity. If the amount spent by 
a client on a particular day is greater than or equal to twice
the client's median spending for a trailing number of days, they 
send the client a notification about potential fraud. The bank
 doesn't send the client any notifications until they have at 
 least that trailing number of prior days' transaction data.

Given the number of trailing days d and a client's total daily expenditures 
for a period of days, find and print the number of times the client will 
receive a notification over all n days.

For example, d = 3 and expenditures = [10, 20, 30, 40, 50]. 
On the first three days, they just collect spending data. At day 4, 
we have trailing expenditures of [10, 20, 30]. The median is 20 and the 
day's expenditure is 40. Because 40 >= 2 * 20, there will be a notice. 
The next day, our trailing expenditures are [20, 30, 40] and the expenditures are 50. 
This is less than 2 * 30, so no notice will be sent. Over the period, 
there was one notice sent.

Note: The median of a list of numbers can be found by arranging all the 
numbers from smallest to greatest. If there is an odd number of numbers, 
the middle one is picked. If there is an even number of numbers, 
median is then defined to be the average of the two middle values.


Input Format
The first line contains two space-separated integers n and d
the number of days of transaction data, and the number of trailing 
days' data used to calculate median spending.
The second line contains n space-separated non-negative integers where 
each integer denotes expenditure.

Constraints
1 <= n <= 2* (10**5)
1 <= d <= n
0 <= expenditure <= 200

Output Format
Print an integer denoting the total number of times the client 
receives a notification over a period of n days.

Sample Input 0
9 5
2 3 4 2 3 6 8 4 5

Sample Output 0
2

Sample Input 1
5 4
1 2 3 4 4

Sample Output 1
0
*/

/*
Since the max of expenditures is fixed, simply maintain
a count array that stores frequency of occurrence of each element
in the trailing days. On shifting the window, this can be updated
in O(1) and calculating median is simply obtaining elements at a given
index based on whether the number of trailing days are odd or even.
*/

#include <bits/stdc++.h>
using namespace std;

unsigned int get_element_at_idx(unsigned int *arr, unsigned int idx);
unsigned int get_twice_median(unsigned int *arr, unsigned int d);

int main(){
    // read the data
    unsigned int n, d, i, j, t[201], count=0; 
    for(i=0; i<201; i++){t[i] = 0;}
    cin >> n >> d;
    unsigned int a[n];
    for(i=0; i<n; i++){cin >> a[i];}
    // start from d+1 and keep track of frauds
    for(i=d; i<n; i++){
        // in the first run, copy the elements and sort the array
        if(i == d){
            // populate the counts array
            for(j=0; j<d; j++){
                t[a[j]]++;
            }       
        }else{
            // remove one element and add another
            // the calculate median
            t[a[i-d-1]]--;
            t[a[i-1]]++;
        }
        // logic
        if(a[i] >= get_twice_median(t, d)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

unsigned int get_element_at_idx(unsigned int *arr, unsigned int idx){
    // get element at a given rank in the array
    unsigned int i, count=0;
    for(i=0; i<201; i++){
        count += arr[i];
        // cout << i << " " << count << " " << idx << endl;
        if(count >= idx){
            return i;
        }
    }
    return 0;
}

unsigned int get_twice_median(unsigned int *arr, unsigned int d){
    // get median from the array representing counts
    unsigned int i, count=0; float median=0;
    if(d%2 == 1){
        // get the d/2 th element
        return 2 * get_element_at_idx(arr, d/2 + 1);
    }else{
        // get the sum of d/2 th and d/2 + 1 th element
        return get_element_at_idx(arr, d/2) + get_element_at_idx(arr, (d/2) + 1);
    }
}
