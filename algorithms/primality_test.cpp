/*
A prime is a natural number greater than that has no positive divisors 
other than and itself. Given q integers, determine the primality of each 
integer and print whether it is Prime or Not prime on a new line.
Note: Solve in O(sqrt(n))

Input Format
The first line contains an integer q denoting the number of integers to 
check for primality. Each of the subsequent q lines contains an integer
n, the number you must test for primality.

Constraints
1 <= q <= 30
1 <= n <= 2*(10**9)

Output Format
For each integer, print whether n is Prime or Not prime on a new line.

Sample Input
4
12
5
7
1

Sample Output
Not prime
Prime
Prime
Not prime
*/

#include <bits/stdc++.h>
using namespace std;

string check_prime(int n);

int main(){
    // read the data
    int q, i; cin >> q;
    int a[q]; for(i = 0; i < q; i++){cin >> a[i];}
    // print whether prime or not
    for(i = 0; i < q; i++){
        cout << check_prime(a[i]) << endl;
    }
    return 0;
}

string check_prime(int n){
    if(n == 1){
        return "Not prime";
    }else if(n == 2 or n == 3){
        return "Prime";
    }else if(n%6 == 1 or n%6 == 5){
        // if n%6 = 0, 2 or 4, the number is even and hence not prime
        // if n%6 = 3, the number is divisible by 3 and hence not prime
        // check the divisors till sqrt(n) as after that the divisors repeat
        int x = sqrt(n), i;
        for(i = 5; i <= x; i++){
            if(n%i == 0){
                return "Not prime";
            }
        }
        return "Prime";
    }else{
        return "Not prime";
    }
    return "Not Prime";
}
