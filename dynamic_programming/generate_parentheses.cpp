/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses. 

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
    1 <= n <= 8
*/

/*
we will use bottom up development of the solution
for n = 1, the solution is trivial ()
for n = 2, the solution is either
    () and ()
    ( () )
ie, either place the brackets individually in the beginning, or keep some
stuff between them
for n = 3, we extend the above idea
    keep the brackets at beginning -> () + all strings with n=2 brackets
    keep 1 pair between brackets -> (all strings n=1) all strings n=1
    keep 2 pair between brackets -> (all strings n=2)

this way, we can keep building the solution once we have solved for all values
of n < current input
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // store all the solutions developed so far
        vector<vector<string>> memoization;
        // here i is 1 less than n (n >= 1)
        for(int i = 0; i < n; i++){
            // store the current answer here
            vector<string> curr_ans;
            // trivial case
            if(i == 0){
                curr_ans.push_back("()");
            }else{
                for(int j = 0; j < i; j++){
                    if(j == 0){
                        for(string s1: memoization[i - 1]){
                            // either place the brackets in beginning
                            curr_ans.push_back("()" + s1);
                            // or place them at the outermost part, and put
                            // the remaining brackets in between
                            curr_ans.push_back("(" + s1 + ")");
                            // in both the cases, the total remaining brackets
                            // are i - 1
                        }
                    }else{
                        // generate all combinations
                        // put some pairs between the current bracket
                        for(string s1: memoization[j-1]){
                            // put the remaining pairs outside afterwards
                            for(string s2: memoization[i - j - 1]){
                                curr_ans.push_back("(" + s1 + ")" + s2);
                            }
                        }
                    }
                }
            }
            // remember to put the solution to the current i in overall solution
            memoization.push_back(curr_ans);
        }
        return memoization[n - 1];
    }
};
