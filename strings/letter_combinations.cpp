// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/*
Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent.
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

A mapping of digit to letters (just like on the telephone buttons) is given 
below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be 
in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<string>>m; 
        m.insert({'2', vector<string>{string("a"), string("b"),  string("c")}});
        m.insert({'3', vector<string>{string("d"), string("e"),  string("f")}});
        m.insert({'4', vector<string>{string("g"), string("h"),  string("i")}});
        m.insert({'5', vector<string>{string("j"), string("k"), string("l")}});
        m.insert({'6', vector<string>{string("m"), string("n"), string("o")}});
        m.insert({'7', vector<string>{string("p"), string("q"), string("r"), string("s")}});
        m.insert({'8', vector<string>{string("t"), string("u"), string("v")}});
        m.insert({'9', vector<string>{string("w"), string("x"), string("y"), string("z")}});
        vector<string>ans; int i = 0;
        // iteratively expand the answer
        while(i < digits.size()){
            auto idx = m.find(digits[i]);
            if(i == 0){
                ans = idx->second;
            }else{
                ans = multiply(ans, idx->second);
            }i--;
        }
        return ans;

    }
    vector<string> multiply(vector<string>ostr, vector<string>nstr){
        // ostr can contain all combinations upto the current char
        // nstr is the list of alphabets present in the current char
        vector<string>ans;
        for(int i = 0;  i < ostr.size(); i++){
            for(int j = 0; j < nstr.size(); j++){
                // the two for loops create cross combinations
                ans.push_back(ostr[i] + nstr[j]);
            }
        }
        return ans;
    }
};
