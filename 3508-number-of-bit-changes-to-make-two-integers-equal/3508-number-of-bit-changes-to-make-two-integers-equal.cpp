class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        for(int i=0; i < 32;i++)
        {
            int a =  n & 1;
            int b = k & 1;
            n = n >> 1;
            k = k >> 1;
            if(a == b)
                continue;
            if(a == 0 && b == 1)
            {
                return -1;
            }
            if(a == 1 && b == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};