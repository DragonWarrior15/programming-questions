// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without 
repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" 
             is a subsequence and not a substring.
*/

/*
the idea is to use sliding windows.. suppose we started searching at some
index start and are currently at index i. we have added all the characters
encountered so far in the map m where we insert the index where we have 
saw the char m.insert({s[i], i}) suppose at some index i, we encounter
a char already in the map.. we know that if we start our search from
idx[key] + 1 till the current index i, all chars in this new window will be
unique and we would have avoided all the repeated computations
this way, we progress the sliding window forward, keeping track of max length

in this above method, we clear the map as soon as we encounter the same char
and restart the process.. there is a subtle optimization by which we can even
save this computation time.. we modify the index of the repeated char to the
current index i. now while checking if the char is in the map, we also check
its index.. if the index stored in map < start index of current search, there is
no need to worry and we update the index to i (current index). thus, there
is no need to modify the map but rather to smartly update it, and we do no 
recalculations/traversal over that old window we had considered

the below codes will make the process clearer
*/

// partially optimized version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, start = 0, end = 0, l_max = 1;
        if(n == 0){return 0;}
        map<char, int>m;
        while(i < n){
            auto idx = m.find(s[i]);
            if(idx == m.end()){
                // new unique character, add to map and substr
                m.insert({s[i], i}); end = i;
                i++;
            }else{
                // character already in map, hence we have reached
                // end of unique char string, adjust l_max
                l_max = max(l_max, end - start + 1);
                // start a new substring search from index of current character
                start = idx->second + 1;
                i = start; end = start;
                m.clear();
            }
        }
        return max(l_max, end - start + 1);
    }
};

// fully optimized version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, start = 0, end = 0, l_max = 1;
        if(n == 0){return 0;}
        map<char, int>m;
        while(i < n){
            auto idx = m.find(s[i]);
            if(idx == m.end()){
                // new unique character, add to map and substr
                m.insert({s[i], i}); end = i;
                i++;
            }else if(idx->second < start){
                // this char has appeared outside the window we are in
                // update this entry with a new index
                idx->second = i;
                end = i; i++; 
            }else{
                // character already in map, hence we have reached
                // end of unique char string, adjust l_max
                l_max = max(l_max, end - start + 1);
                // start a new substring search from index of current character
                start = idx->second + 1;
                // modify the index of repeated char since the old one is now
                // not relevant and in the above else if check, we are already
                // checking if the index in map > start index
                idx->second = i;
                end = i; i++;
            }
        }
        return max(l_max, end - start + 1);
    }
};
