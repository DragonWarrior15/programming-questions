/*
Lexicographical order is often known as alphabetical order when dealing with 
strings. A string is greater than another string if it comes later in a 
lexicographically sorted list.
Given a word, create a new word by swapping some or all of its characters. 
This new word must meet two criteria:
    It must be greater than the original word
    It must be the smallest word that meets the first condition

For example, given the word w = abcd, the next largest word is abdc.

Input Format
The first line of input contains T, the number of test cases.
Each of the next T lines contains a string w.

Constraints
1 <= T <= 10**5
1 <= |w| <= 100
w will contain only letters in the range ascii[a..z].

Output Format
For each test case, output the string meeting the criteria. If no answer exists, 
print no answer.

Sample Input 0
5
ab
bb
hefg
dhck
dkhc

Sample Output 0
ba
no answer
hegf
dhkc
hcdk

Explanation 0
Test case 1:
ba is the only string which can be made by rearranging ab. It is greater.
Test case 2:
It is not possible to rearrange bb and get a greater string.
Test case 3:
hegf is the next string greater than hefg.
Test case 4:
dhkc is the next string greater than dhck.
Test case 5:
hcdk is the next string greater than dkhc.

Sample Input 1
6
lmno
dcba
dcbb
abdc
abcd
fedcbabcd

Sample Output 1
lmon
no answer
no answer
acbd
abdc
fedcbabdc


*/

#include <bits/stdc++.h>
using namespace std;

string get_next_lexicographical_string(string w);

int main(){
    // read data
    int T; string w, temp;
    getline(cin, temp); T = stoi(temp);
    while(T--){
        getline(cin, w);
        // get the next lexographically larger string
        cout << get_next_lexicographical_string(w) << endl;
    }
    return 0;
}

string get_next_lexicographical_string(string w){
    /*
    the algorithm has the following steps
    1) if the string is sorted in descending order, this is the largest
       lexographical string, return this
    2) otherwise, starting from the right side, find a char in the string
       that is not in descending order, or the out of order char to say
    3) find the next largest char after this char to the right of
       this char in the string and swap these two
    4) now, for the chars to the right of the position where we found the
       first out of order char, sort them in ascending order
    5) return the new string formed
    */
    int i = w.size() - 1, pos, pos_next; char next;
    while(1){
        if(i == 0){
            // the string is the largest string, return
            return "no answer";
        }else{
            // compare this and the left character
            if(w[i - 1] >= w[i]){
                // correct order, continue
                i--;
            }else{
                // found the position with incorrect char
                pos = i - 1;
                // now locate the next smallest char
                i = pos + 1;
                stack<int> s;
                while(i < w.size()){
                    if(w[i] > w[pos]){
                        // keep in stack for now
                        s.push(i);
                    }
                    i++;
                }
                // get the minimum among the chars in stack
                next = w[s.top()]; pos_next = s.top(); s.pop();
                while(!s.empty()){
                    if(next > w[s.top()]){
                        next = w[s.top()];
                        pos_next = s.top();
                    }
                    s.pop();
                }
                // swap pos and pos_next
                next = w[pos]; w[pos] = w[pos_next]; w[pos_next] = next;
                // sort the elements to the right of pos in ascending order
                // which is same as reversing the string since elements already
                // are in descending order
                stack<char> s1;
                for(i = pos + 1; i < w.size(); i++){
                    s1.push(w[i]);
                }
                for(i = pos + 1; i < w.size(); i++){
                    w[i] = s1.top(); s1.pop();
                }                
                return w;
            }
        }
    }
    return w;
}
