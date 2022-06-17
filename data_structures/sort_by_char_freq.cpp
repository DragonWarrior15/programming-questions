/*
https://leetcode.com/problems/sort-characters-by-frequency/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is 
also a valid answer.

Example 2:
Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        // first store the character frequency in a map
        // then use the map to populate a priority queue
        // where priority is based on the frequency
        // return the answer by popping the priority queue
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        // by default a max heap based on the first element is created
        priority_queue<pair<int, char>> pq;
        for(auto itr = m.begin(); itr != m.end(); itr++){
            pq.push({itr->second, itr->first});
        }
        string ans;
        while(!pq.empty()){
            for(int i = 0; i < pq.top().first; i++){
                ans += pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};
