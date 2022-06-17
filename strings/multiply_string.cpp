// https://leetcode.com/problems/multiply-strings/
/*
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == to_string(0) or num2 == to_string(0)){
            return "0";
        }

        int n1 = num1.size(), n2 = num2.size(), i, j, idx, d1, d2, current, carry_over;
        vector<int> ans(n1+n2+2, 0);

        // vector ans is filled in reverse, i.e., units digit of answer
        // will be at index 0 and so on
        // i corresponds to the second number since in multiplication by
        // hand, we first multiply a digit of the second number
        // with all the digits of the first number
        for(i = n2-1; i >= 0; i--){
            for(j = n1-1; j >= 0; j--){
                // idx denotes the location at which to calculate
                // and put the answer of multiplication of these
                // two digits
                idx = (n1-1 + n2-1) - (i+j);
                d1 = stoi(num1.substr(j,1));
                d2 = stoi(num2.substr(i,1));
                current = ans[idx];
                ans[idx] = (current + d1*d2)%10;
                // remember to create the carry over and continue till
                // it exists
                carry_over = (current + d1*d2)/10;
                while(carry_over){
                    idx++;
                    current = ans[idx];
                    ans[idx] = (current + carry_over)%10;
                    carry_over = (current + carry_over)/10;
                }
            }
        }

        string s;
        // since the size of ans is more than the actual digits
        // we need to find the index till we have "leading" zeros
        if(ans[ans.size()-1] != 0){
            idx = ans.size()-1;
        }else{
            idx = ans.size()-1;
            while(true){
                if(ans[idx] == 0){
                    // keep checking
                    idx--;
                }else{
                    // found non zero digit
                    break;
                }
            }
        }
        for(i = idx; i >=0; i--){
            s.append(to_string(ans[i]));
        }
        return s;
    }
};
