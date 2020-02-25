/*
A bracket is considered to be any one of the following characters: 
(, ), {, }, [, or ].
Two brackets are considered to be a matched pair if the opening bracket 
(i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) 
of the exact same type. There are three types of matched pairs of brackets: 
[], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses 
are not matched. For example, {[(])} is not balanced because the contents i
n between { and } are not balanced. The pair of square brackets encloses a single, 
unbalanced opening bracket, (, and the pair of parentheses encloses a single, 
unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:
    It contains no unmatched brackets.
    The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.

Given n strings of brackets, determine whether each sequence of brackets is balanced. 
If a string is balanced, return YES. Otherwise, return NO.


Input Format
The first line contains a single integer n the number of strings.
Each of the next lines contains a single string s a sequence of brackets.

Constraints
1 <= n <= 1000
1 <= |s| <= 1000
All chracters in the sequences are in {, }, (, ), [, ].

Output Format
For each string, return YES or NO.

Sample Input
3
{[()]}
{[(])}
{{[[(())]]}}

Sample Output

YES
NO
YES

Explanation
The string {[()]} meets both criteria for being a balanced string, so we print YES on a new line.
The string {[(])} is not balanced because the brackets enclosed by the matched pair { and } are not balanced: [(]).
The string {{[[(())]]}} meets both criteria for being a balanced string, so we print YES on a new line.
*/

#include <bits/stdc++.h>
using namespace std;

unsigned short int balanced_string(string s);

int main(){
    // read the data
    short int i, n; string s;
    getline(cin, s); n = stoi(s);
    while(n--){
        getline(cin, s);
        if(balanced_string(s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

unsigned short int balanced_string(string s){
    // simply create a new string to act like a stack
    short int stack_idx = 0, string_idx = 0; string s1 = s;
    while(1){
        // cout << stack_idx << " " << string_idx<< endl;
        if(string_idx == 0){
            // just beginning to add data to stack
            s1[stack_idx] = s[string_idx];
            string_idx++;
        }else if(string_idx == s.size() and stack_idx == -1){
            // complete string checked
            return 1;
        }else if(s[string_idx] == '(' or
                 s[string_idx] == '[' or
                 s[string_idx] == '{'){
            // add this to the stack
            stack_idx++;
            s[stack_idx] = s[string_idx];
            string_idx++;
        }else if((s[string_idx] == ')' and s[stack_idx] == '(') or
                 (s[string_idx] == ']' and s[stack_idx] == '[') or
                 (s[string_idx] == '}' and s[stack_idx] == '{')){
            // we have encountered a valid closing bracket
            string_idx++; stack_idx--;
        }else{
            // not a valid closing bracket
            return 0;
        }
    }
    return 0;
}