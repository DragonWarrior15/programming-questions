/*
We define super digit of an integer x using the following rules:
Given an integer, we need to find the super digit of the integer.
    If x has only q digit, then its super digit is x.
    Otherwise, the super digit of x is equal to the super digit of the 
    sum of the digits of x.

For example, the super digit of 9875 will be calculated as:

    super_digit(9875)       9+8+7+5 = 29 
    super_digit(29)     2 + 9 = 11
    super_digit(11)     1 + 1 = 2
    super_digit(2)      = 2  

You are given two numbers n and k. The number is created by concatenating the 
string k times. Continuing the above example where n = 9875, assume your value 
of k = 4. 
    superDigit(p) = superDigit(9875987598759875)
                  5+7+8+9+5+7+8+9+5+7+8+9+5+7+8+9 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)

Input Format

The first line contains two space separated integers n and k.

Constraints
1 <= n <= 10**10000
1 <= k <= 10**5

Output Format
Return the super digit of n concatenated k times

Sample Input 0
148 3

Sample Output 0
3

Explanation 0
Here n = 148 and k = 3
super_digit(P) = super_digit(148148148) 
               = super_digit(1+4+8+1+4+8+1+4+8)
               = super_digit(39)
               = super_digit(3+9)
               = super_digit(12)
               = super_digit(1+2)
               = super_digit(3)
               = 3.

Sample Input 1
9875 4

Sample Output 1
8

Sample Input 2
123 3

Sample Output 2
9

Explanation 2
Here n = 123 and k = 3, so
super_digit(P) = super_digit(123123123) 
               = super_digit(1+2+3+1+2+3+1+2+3)
               = super_digit(18)
               = super_digit(1+8)
               = super_digit(9)
               = 9

*/

/*
9 + any digit k = k, use this property recursively
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    string s; long k, i; getline(cin, s); int n = 0;
    for(i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            // reduce the number to a single digit sum
            // use the property that 9 + any single digit number
            // is the same number itself
            if(n == 0){;}
            else if(n == 9){;}
            else if(n%9 == 0){9;}
            else{n = n%9;}
            // get the value of k
            k = stol(s.substr(i+1, s.length()));
            break;
        }else{
            n += (s[i] - '0');
            if(n == 0){;}
            else if(n%9 == 0){9;}
            else{n %= 9;}
        }
    }
    // get the final sum to output
    k = n * k;
    if(k == 0){;}
    else if(k == 9){;}
    else if(k%9 == 0){k = 9;}
    else{k = k%9;}
    cout << k << endl;
    return 0;
}