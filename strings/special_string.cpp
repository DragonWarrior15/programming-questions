/*
A string is said to be a special string if either of two conditions is met:
    All of the characters are the same, e.g. aaa.
    All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. 
Given a string, determine how many special substrings can be formed from it.

For example, given the string mnonopoo, we have the following special substrings:
{m, n, i, m, i, p, o, o, non, ono, opo, oo}.

Input Format
The first line contains an integer n the length of the string
The second line contains the string s.

Constraints
1 <= |s| <= 10**6
s is in [a-z]

Output Format
Print a single line containing the count of total special substrings.

Sample Input 0
5
asasd

Sample Output 0
7 

Explanation 0
{a, s, a, s, d, asa, sas}

Sample Input 1
7
abcbaba

Sample Output 1
10 

Explanation 1
{a, b, c, b, a, b, a, bcb, bab, aba}

Sample Input 2
4
aaaa

Sample Output 2
10

Explanation 2
{a, a, a, a, aa, aa, aa, aaa, aaa, aaaa}
*/

/*
checking every substring is O(n2), so we use the fact that
only the middle character should be different, and when we have already
compared some elements, no need to compare them again, check the logic
below for the implementation
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int n, count=0, i, j, k; string s;
    // read data
    getline(cin, s); n = stoi(s);
    getline(cin, s);
    // begin calculating
    // every individual letter satisfies the conditions
    count += n;
    if(n == 2){
        if(s[0] == s[1]){
            count++;
        }
    }else{
        // start to track either sets of repeating letters
        // or atleast length 3 strings with all but middle letters same
        i = 0, j = 1;
        while(j < n){
            if(s[j] == s[i]){
                // block of repeating characters, continue checking
                j++;
            }else{
                // a different character is encountered,
                // first add the combinations from the block of on the left
                // side of the different character
                // (dont count single letters as they have already been added above)
                if(j - i > 1){
                    count += ((j - i) * (j - i - 1))/2;
                }
                // start checking the chars after the jth index, the right hand side
                k = j + 1;
                while(k < n){
                    if(s[k] != s[i]){
                        // do this so as to not step out of the same
                        // characters batch on right side
                        k--;
                        break;
                    }else{
                        // continue checking
                        k++;
                    }
                }
                // limit the value of k to last valid index
                if(k >= n){k = n - 1;} 
                // run of repeating chars on right side ended
                // add this set to the count if it is valid
                if(s[k] == s[i]){
                    if(k - j == j - i){
                        // check if the end chars are same
                        count += j - i;
                    }else if(k - j > j - i){
                        count += j - i;
                    }else{
                        count += k - j;
                    }
                }
                // search on other side has terminated, reset i and j
                // check on the left side first to get the set of repeating 
                // characters, k will be set when we start searching on right side
                i = j; j = i + 1;
            }
        }
        // in case of reaching end of string with a run of same chars
        if(j - i > 1){
            count += ((j - i) * (j - i - 1))/2;
        }
    }
    cout << count << endl;
    return 0;
}