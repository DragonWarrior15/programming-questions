/*
Given 2 strings, P and T, find the number of occurrences of P in T.

Input:
First line contains string P, and second line contains the string T.

Output:
Print a single integer, the number of occurrences of P in T.

Constraints:
1 <= |P| <= |T| <= 10^5
*/

/*
kmp algorithm
the kmp algorithm works by using patterns in the pattern itself
first we need to know an lps array
create an lps (longest proper prefix also a suffix)
lps[i] will indicate the length of longest prefix in P[0..i] 
that is also a suffix in P[0..i]
example, lps of aabaa is 01012
consider a matching example
aabacaa
aabaa
we start with i=0 and j=0, keep incrementing them while there is a match
we reach i=4 and j=4 at first mismatch, now notice that lps[j-1] tells us
the longest suffix that matches prefix, and since pattern matches text for
first j-1 chars, we can simply slide the pattern lps[j-1] characters, see below
where the longest prefix and suffix are marked in <> brackets
<a>ab<a>caa
<a>ab<a>a
now we simply slide the pattern such that the angular brackets align again
<a>ab<a>caa
     <a>ab<a>a
and since we know the prefix and suffix match, we can start the comparison from
the next character after the prefix
aabacaa
   aabaa
start comparing a and c next and the cycle repeats

creating ths lps array
we greedily try to match the maximum length possible at any index
see the code for complete implementation
*/
#include <iostream>
using namespace std;

int main(){
    char P[100000], T[100000];
    cin >> P >> T;
    // create the lps array
    int i = 0, j, pattern_length, len;
    while(P[i] != '\0'){i++;}
    pattern_length = i;
    int lps[pattern_length];
    // lps[0] always 0
    lps[0] = 0; i = 1, len = 0;
    while(P[i] != '\0'){
        // check if pattern at length and i match
        if(P[i] == P[len]){
            // in this "longer" array, we have longer matching prefix and suffix
            // hence, update the lps value at this index by length + 1 (match size)
            lps[i] = len+1; len += 1; i += 1;
        }else if(P[i] != P[len] && len > 0){
            // patterns not match, try matching a shorter length
            len = lps[len-1];
        }else{
            // no patterns have matched, increment i and start
            // comparing this with the first character
            lps[i] = 0; i += 1;
        }
    }
    // for(i=0; i<pattern_length; i++){cout << lps[i] << " ";}cout << endl;

    // kmp algorithm
    int matches = 0;
    i = 0; j = 0;
    while(T[i] != '\0'){
        // cout << i << " " << j << endl;
        if(j == pattern_length){
            // whole pattern is matched
            matches++; j = lps[j-1];
        }else if(T[i] == P[j]){
            // if chars match, go on to match the next one
            i++; j++;
        }else if(j == 0){
            // no further matching is possible, go to text next character
            i++;
        }else{
            // if chars don't match, shift the pattern using
            // the lps array
            j = lps[j-1];
        }
    }if(j==pattern_length){matches++;}

    cout << matches << endl;

    return 0;
}