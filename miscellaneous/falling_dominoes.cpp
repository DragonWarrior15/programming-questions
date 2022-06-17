/*
https://leetcode.com/problems/push-dominoes/submissions/

There are N dominoes in a line, and we place each domino vertically upright.
In the beginning, we simultaneously push some of the dominoes either to the 
left or to the right.
After each second, each domino that is falling to the left pushes the adjacent 
domino on the left.
Similarly, the dominoes falling to the right push their adjacent dominoes 
standing on the right.
When a vertical domino has dominoes falling on it from both sides, it stays 
still due to the balance of the forces.
For the purposes of this question, we will consider that a falling domino 
expends no additional force to a falling or already fallen domino.
Given a string "S" representing the initial state. S[i] = 'L', if the i-th 
domino has been pushed to the left; S[i] = 'R', if the i-th domino has been 
pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
Return a string representing the final state. 

Example 1:
Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Example 2:
Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Note:
    0 <= N <= 10^5
    String dominoes contains only 'L', 'R' and '.'
*/

/* the logic is to start solving from left recursively
and write specific code for some of the special cases*/

class Solution {
void solve(string& dominoes, int idx){
    if(idx >= dominoes.size()){return;}
    int next_idx = idx;
    // solve this recursively starting from the left side
    // get the first index of a topple
    for(int i = idx; i < dominoes.size(); i++){
        if(dominoes[i] == 'L'){
            // topple everything from i to idx
            for(int j = idx; j <= i; j++){
                dominoes[j] = 'L';
            }
            next_idx = i + 1;
            break;
        }else if(dominoes[i] == 'R'){
            // try to search for a matching 'L'
            for(int j = i + 1; j < dominoes.size(); j++){
                if(dominoes[j] == 'L'){
                    next_idx = j + 1;
                    // find the middle point and accordingly set toppled state
                    for(int k = i; k <= j; k++){
                        if(k <= i + (j - i)/2){
                            dominoes[k] = 'R';
                        }
                        if(k > i + (j - i)/2){
                            dominoes[k] = 'L';
                        }
                        // cout << "[1] " << j << " " << i << " " << k << " " << dominoes[k] << " " << next_idx << endl; 
                    }
                    if((j - i)%2 == 0){
                        dominoes[(j + i)/2] = '.';
                    }
                    break;
                }else if(dominoes[j] == 'R'){
                    next_idx = j;
                    // everything in between must fall
                    for(int k = i; k < j; k++){
                        dominoes[k] = 'R';
                    }
                    break;
                }else{}
            }
            if(next_idx == idx){
                // topple everything
                for(int j = i; j < dominoes.size(); j++){
                    dominoes[j] = 'R';
                }
            }
            break;
        }else{
            // nothing to do, continue
            continue;
        }
    }
    // cout << "[2] " << idx << " " << next_idx << endl;
    if(next_idx == idx){
        // nothing found to topple, return
        return;
    }else{
        solve(dominoes, next_idx);
    }
}
public:
    string pushDominoes(string dominoes) {
        if(dominoes.size() == 0){return dominoes;}
        solve(dominoes, 0);
        return dominoes;
    }
};
