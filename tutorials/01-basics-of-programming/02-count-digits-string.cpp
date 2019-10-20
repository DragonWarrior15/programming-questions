/*
You are given a string S. Count the number of occurrences of all the digits in the string S.
Input:
First line contains string S.
Output:
For each digit starting from 0 to 9, print the count of their occurrences in the string S. 
So, print lines, each line containing 2 space separated integers. 
First integer i and second integer count of occurrence of i. See sample output for clarification.

Constraints: 1 <= |S| <= 100

SAMPLE INPUT
77150

SAMPLE OUTPUT
0 1
1 1
2 0
3 0
4 0
5 1
6 0
7 2
8 0
9 0
*/

// Write your code here
#include <iostream>
#include <string>
using namespace std;
int main(){
    int count[10], i=0;
    for(i=0; i<10; i++){
        count[i] = 0;
    }
    char num[100];
    cin >> num;
    for(i=0; i<100; i++){
        if(num[i] != '\0'){
            count[num[i] - '0'] += 1;
        }else{
            break;
        }
    }
    for(i=0; i<10; i++){
        cout << i << " " << count[i] << endl;
    }
    return 0;
}
