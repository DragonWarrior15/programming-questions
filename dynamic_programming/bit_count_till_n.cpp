// https://leetcode.com/problems/counting-bits/
/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
    But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function 
    like __builtin_popcount in c++ or in any other language.
*/

/*
the logic of the solution exploits the fact that we can use some
of the precalculated bit counts
suppose we know the bit counts of all numbers till 2^n. now the bit count
in 2^n+1 is simply bit count(2^n) + bit count(1) because the highest bit of 2^n
till 2^(n+1)-1 will always be set and only the other bits will change
bit count(2^n+4) = bit count(2^n) + bit count(4)

thus, for calculating bit counts of 2^n+1 to 2^(n+1)-1 we simply do
1 + bit count(1) to 1 + bit count(2^n-1) all of which we have already
calculated earlier when going from 2^(n-1) to 2^(n-1)-1.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0){
            return vector<int>(1, 0) ;
        }
        vector<int> answer(num+1, 0); answer[0] = 0; answer[1] = 1;
        int i=1, j=1;
        while(i+j <= num){
            if(i == j){
                // we have reached a power of 2
                answer[i+j] = 1;
                i = i+j; j=1;
            }else{
                // we are working at 2^n + j, i=2^n
                answer[i+j] = answer[i] + answer[j];
                j++;
            }
        }
        
        return answer;
    }
};
