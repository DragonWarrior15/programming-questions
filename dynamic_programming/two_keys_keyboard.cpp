// https://leetcode.com/problems/2-keys-keyboard/
/*
Initially on a notepad only one character 'A' is present. 
You can perform two operations on this notepad for each step:
    Copy All: You can copy all the characters present on the notepad 
              (partial copy is not allowed).
    Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by 
performing the minimum number of steps permitted. Output the minimum 
number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
    The n will be in the range [1, 1000].
*/

class Solution {
public:
    int minSteps(int n) {
        if(n <= 1){
            return 0;
        }
        vector<int> prime_list;
        prime_list.push_back(2);       
        int sq, j;
        vector<int> ans(n+1, 0);
        ans[1] = 0; ans[2] = 2;
        for(int i = 3; i <= n; i++){
            if(i%2 == 0){
                // for even numbers, the last operation will be a copy paste
                // hence total operations will be a[i/2] + (1 + 1)
                ans[i] = ans[i/2] + 2;
            }else{
                // for prime numbers, we simply copy the single
                // character A, because we are only allowed to paste the
                // text last copied and prime numbers are not divisible
                // by any number other than 1
                for(int x: prime_list){
                    if(i%x == 0){
                        // not a prime number
                        
                        // we need to minimize the operations
                        // the easiest way is to get upto some number and
                        // then copy paste it rapidly.. for this we look
                        // across all the possible divisor pairs of the number
                        // x is the smallest divisor
                        sq = sqrt(i);
                        ans[i] = INT_MAX;
                        for(j = x; j <= sq; j++){
                            if(i%j == 0){
                                // we have the pairs required to calculate
                                ans[i] = min(ans[i], min(ans[i/j] + 1 + (j - 1), 
                                             ans[j] + 1  + (i/j - 1)));
                            }
                        }
                        break;
                    }
                }
                if(ans[i] == 0){
                    // prime
                    prime_list.push_back(i);
                    ans[i] = i;
                }
            }
        }
        return ans[n];
    }
};
