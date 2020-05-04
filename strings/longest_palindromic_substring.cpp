// https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/practice-problems/algorithm/longest-palindromic-string/
// https://leetcode.com/problems/longest-palindromic-substring/submissions/
/*
Given a string S, find the longest palindromic substring in the string S.

Input:
First and only line will contain string S.

Output:
Print the length of the longest palindrome substring in the first line.
In the second line print the longest palindromic substring in S. 
If there is more than one palindromic substring with the maximum length, 
output the first one.

SAMPLE INPUT
czcaba

SAMPLE OUTPUT
3
czc

Constraints:
1 <= N <= 10**5
String S will only contain lower case English alphabet [a-z]. 
*/

#include <bits/stdc++.h>
// #include <string>
using namespace std;

int main(){
    unsigned int n, max_len_palindrome=0, max_start, max_end, i, x; 
    string s;
    // read the data
    getline(cin, s);
    n = s.size();

    // part 1 for palindromes of length odd, length 1 is also palindrome
    for(i=0; i<n; i++){
        // treating i as the centre, x is the maximum we can go either side
        for(x=0; x<=min(n-1-i, i); x++){
            // string at indices [L,R] is palindrome if [L-1,R-1] is 
            // palindrome && char at L == char at R, thus we can start at center
            // and expand outwards, only comparing the terminal characters
            if(s[i-x] == s[i+x]){
                // palindrome exists
                if(2*x + 1 > max_len_palindrome){
                    max_len_palindrome = 2*x + 1;
                    max_start = i-x; max_end = i+x;
                }
            }else{
                break;
            }
        }
    }

    // part 2 for palindromes of even length
    for(i=0; i<n; i++){
        // i will be the left side of the smallest length 2 string and we expand
        // outwards, only comparing the outermost indices
        for(x=0; x<=min(n-1-i, i); x++){
            if(s[i-x] == s[i+1+x]){
                // palindrome of even length found
                if(2*x+2 > max_len_palindrome){
                    max_len_palindrome = 2*x+2;
                    max_start = i-x; max_end = i+1+x;
                }
            }else{
                break;
            }
        }
    }

    // print the answer
    cout << max_len_palindrome << endl << s.substr(max_start, max_end - max_start + 1);

    return 0;
}