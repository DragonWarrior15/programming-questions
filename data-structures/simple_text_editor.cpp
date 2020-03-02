/*
In this challenge, you must implement a simple text editor. Initially, 
your editor contains an empty string S. You must perform operations of the 
following 4 types:
1 append(W) : append string W to end of S
2 delete(k) : delete last k characters from S
3 print(k) : print kth character (1 indexed) of S
4 undo : undo the last operation of type 1 or 2

Input Format
The first line contains an integer Q denoting the number of operations.
Each line of the subsequent Q lines defines an operation to be performed. 
Each operation starts with a single integer t (where t in [1,2,3,4]), 
denoting a type of operation as defined in the Problem Statement above. 
If the operation requires an argument, is followed by its space-separated argument. 
For example, if t = 1 and W = abcd, line will be 1 abcd.

Constraints
1 <= Q <= 10**6
1 <= k <= |S|
The sum of the lengths of all in the input <= 10**6.
The sum of k over all delete operations <= 2 * 10**6
All input characters are lowercase English letters.
It is guaranteed that the sequence of operations given as input is possible to perform.

Output Format
Each operation of type 3 must print the kth character (1 indexed) on a new line.

Sample Input
8
1 abc
3 3
2 3
1 xy
3 2
4 
4 
3 1

Sample Output
c
y
a
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read the data
    int Q, k; string S, temp; stack<int> op; stack<string> w;
    getline(cin, temp); Q = stoi(temp);
    while(Q--){
        // read the query
        getline(cin, temp);
        if(temp.size() == 1){
            // query of type 4
            // get the op and temp string
            k = op.top();
            if(k == 1){
                // remove the last appended string
                temp = w.top();
                S = S.substr(0, S.size() - temp.size());
            }else{
                // add the last deleted characters
                S = S.append(w.top());
            }
            op.pop(); w.pop();
        }else{
            if(temp[0] == '1'){
                // append operation
                temp = temp.substr(2, temp.size() - 2);
                // append to string S
                S = S.append(temp);
                // add to history stacks
                op.push(1); w.push(temp);
            }else if(temp[0] == '2'){
                // delete operation
                k = stoi(temp.substr(2, temp.size() - 2));
                op.push(2); w.push(S.substr(S.size() - k, k));
                S = S.substr(0, S.size() - k);
            }else{
                // print operation
                k = stoi(temp.substr(2, temp.size() - 2));
                cout << S[k - 1] << endl;
            }
        }
    }
    return 0;
}