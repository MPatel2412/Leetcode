class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRounds = (time)/(n-1);
        int incomplete = time%(n-1);

        if(fullRounds%2 ==0 )
        {
            return incomplete + 1;
        }
        else
        {
            return n - incomplete;
        }
    }
};