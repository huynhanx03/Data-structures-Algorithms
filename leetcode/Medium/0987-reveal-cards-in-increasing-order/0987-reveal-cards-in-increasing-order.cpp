/*
 Problem: 987. Reveal Cards In Increasing Order
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13 MB (6.81%)
 Tags: Array, Queue, Sorting, Simulation
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.rbegin(), deck.rend());
        deque<int> de{deck[0]};

        for (int i = 1; i < n; ++i) {
            int back = de.back();
            de.pop_back();
            de.push_front(back);
            de.push_front(deck[i]);
        }

        return vector<int>(de.begin(), de.end());
    }
};