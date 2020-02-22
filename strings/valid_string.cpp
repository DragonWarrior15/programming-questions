/*
Sherlock considers a string to be valid if all characters of the 
string appear the same number of times. It is also valid if he can 
remove just 1 character at 1 index in the string, and the remaining 
characters will occur the same number of times. Given a string s, 
determine if it is valid. If so, return YES, otherwise return NO.

For example, if s = abc, it is a valid string because frequencies are 
1 for all characters. s = abcc is also valid because removing one c
makes the string valid. s = abccc is not valid because removing one c
will not make the freuquencies of all the remaining characters same.

Input Format
A single string s

Constraints
1 <= |s| <= 10**5
s is in [a-z]

Output Format
Print YES if string s is valid, otherwise, print NO.

Sample Input 0
aabbcd

Sample Output 0
NO


Sample Input 1
aabbccddeefghi

Sample Output 1
NO

Sample Input 2
abcdefghhgfedecba

Sample Output 2
YES
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    unsigned int i, j, temp, a[26];
    for(i=0; i<26; i++){a[i] = 0;}
    string s;
    getline(cin, s);
    for(i=0; i<s.length(); i++){
        a[(int)s[i] - 97]++;
    }
    // hashmap to track distinct values of counts
    map<unsigned int, unsigned int> counts;
    for(i=0; i<26; i++){
        if(a[i]){
            auto idx = counts.find(a[i]);
            if(idx != counts.end()){
                idx -> second += 1;
            }else{
                counts.insert({a[i], 1});
            }
        }
    }
    map<unsigned int, unsigned int>::iterator itr; i = 0;
    for (itr = counts.begin(); itr != counts.end(); itr++){
        i++;
    }
    if(i >= 3){
        cout << "NO" << endl;
    }else if(i == 1){
        cout << "YES" << endl;
    }else{
        i = 0, j = 0;
        // distinct counts are 2
        itr = counts.begin();
        i = itr -> first;
        itr ++;
        j = itr -> first;
        if(i > j){
            temp = i; i = j; j = temp;
        }
        // corener cases is the check after the or
        if((j == i + 1 and counts.find(j)->second == 1)
           or (i == 1 and counts.find(i)->second == 1)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}