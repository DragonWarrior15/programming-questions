/*
https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
*/
class Solution {
public:
    int trailingZeroes(int n) {
        // calculate the multiples of 2, 4,..
        int x = 2, count_2 = 0, count_5 = 0;
        while(1){
            if(x > n){
                break;
            }else{
                count_2 += n/x;
                x *= 2;
            }
        }
        // similarly calculate the multiples of 5, 25,..
        x = 5;
        while(1){
            if(x > n){
                break;
            }else{
                count_5 += n/x;
                x *= 5;
            }
        }
        if(count_2 * count_5 == 0){
            return 0;
        }else if(count_2 <= count_5){
            return count_2;
        }else{
            return count_5;
        }

        return 0;
    }
};
