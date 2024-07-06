class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1;
        int direction = 1;
        while(time--)
        {
            index = index + direction;
            if(index == n || index == 1)
                direction *= -1;
        }
        return index;
    }
};