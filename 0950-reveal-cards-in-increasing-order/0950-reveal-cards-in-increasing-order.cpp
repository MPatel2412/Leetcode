class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        for (int i = 0; i < N; i++) 
        {
            queue.push(i);
        }
        
        sort(deck.begin(), deck.end());
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            int index = queue.front();
            result[index] = deck[i];
            queue.pop();

            // Move next card to bottom
            if (!queue.empty()) 
            {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};