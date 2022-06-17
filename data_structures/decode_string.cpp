/*
https://leetcode.com/problems/decode-string/

Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the 
square brackets is being repeated exactly k times. Note that k is guaranteed 
to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, 
square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any 
digits and that digits are only for those repeat numbers, k. For example, 
there won't be input like 3a or 2[4].

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

Constraints:
    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
*/

class Solution {
public:
    string decodeString(string s) {
        // work through the example below and the algorithm to understand
        // how the solution works
        // an example string 3[a2[c]]
        int idx = 0;
        // stacks are used because of nesting, we need to repeat whatever was
        // closest to the current string
        // a stack to store the intermediate strings, this is necessary since
        // there can be nested expressions as well
        stack<string> stack_s; stack_s.push("");
        // a stack to store the counts of repetitions, again necessary since
        // there can be nested expressions
        stack<int> stack_count;
        string num, duplicated_str, ans;
        while(idx < s.size()){
            if(s[idx] == '['){
                // we have completely read a number 
                // whatever is in num, add to the integer stack
                stack_count.push(stoi(num));
                // reset num
                num.clear();
                // create space for storing a new string on top of stack_s
                stack_s.push("");
            }else if(s[idx] == ']'){
                // we must replicate num a fixed no of times
                // where we use the int stack to get the count
                duplicated_str.clear();
                for(int i = 0; i < stack_count.top(); i++){
                    duplicated_str += stack_s.top();
                }
                stack_count.pop(); stack_s.pop();
                // now append this to whatever is on top of the stack
                duplicated_str = stack_s.top() + duplicated_str; stack_s.pop();
                stack_s.push(duplicated_str);
                // reset duplicated string
                duplicated_str.clear();
            }else if('0' <= s[idx] && s[idx] <= '9'){
                // we are passing through a number, add to num
                num += s[idx];
            }else{
                // this must be a char, append it to top of stack
                ans = stack_s.top() + s[idx];
                stack_s.pop(); stack_s.push(ans);
                ans.clear();
            }
            idx++;
        }
        // keep adding all the entries in the stack
        while(!stack_s.empty()){
            ans += stack_s.top(); stack_s.pop();
        }
        return ans;
    }
};
