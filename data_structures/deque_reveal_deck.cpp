// https://leetcode.com/problems/reveal-cards-in-increasing-order/
/*
In a deck of cards, every card has a unique integer.  You can order the deck in 
any order you want.
Initially, all the cards start face down (unrevealed) in one deck.
Now, you do the following steps repeatedly, until all cards are revealed:
    Take the top card of the deck, reveal it, and take it out of the deck.
    If there are still cards in the deck, put the next top card of the deck at 
    the bottom of the deck.
    If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.
The first entry in the answer is considered to be the top of the deck.

Example 1:
Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), 
and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top 
of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.

Note:
    1 <= A.length <= 1000
    1 <= A[i] <= 10^6
    A[i] != A[j] for all i != j
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size() <= 1){return deck;}
        deque<int>dq; int temp;
        // sort the deck in ascending order
        sort(deck.begin(), deck.end());
        // put the last element into the deque as is
        dq.push_front(deck[deck.size()-1]);
        for(int i = deck.size()-2; i >= 0; i--){
            // if we see the above example in problem and follow it backwards,
            // what we are doing anytime is bringing the last element to the
            // front, and adding the current element in the deck to the top
            // this is the exact reverse of the steps that are given to us
            // in the problem statement
            // since we are working with add/remove at both front and end,
            // we use double ended queue
            temp = dq.back(); dq.pop_back();
            dq.push_front(temp);
            dq.push_front(deck[i]);
        }
        // the deque has the correct order of elements.. push them
        // in the same order into the vector for function to return
        vector<int>answer;
        while(!dq.empty()){
            answer.push_back(dq.front());
            dq.pop_front();
        }
        return answer;
    }
};
