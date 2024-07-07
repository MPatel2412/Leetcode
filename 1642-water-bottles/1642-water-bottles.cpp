class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        int empty = 0;
        int prev = 0;
        while(numBottles > 0)
        {
            cnt += (numBottles);
            empty = numBottles + prev;
            
            numBottles = floor(empty/numExchange);
            prev = (empty%numExchange);
        }
        return cnt;
    }
};