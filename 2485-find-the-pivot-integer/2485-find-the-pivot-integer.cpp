class Solution {
public:
    int pivotInteger(int n) {
        vector<int> pre(1001);
        pre[0] = 0;
        int ans = -1;
        for(int i=1;i<=1000;i++)
        {
            pre[i] = pre[i-1] + i;
        }
        
        for(int i=1;i<=n;i++)
        {
                int sum1 = pre[n] - pre[i-1];
                int sum2 = pre[i];
                if(sum1 == sum2)
                {
                    ans = i;
                    break;
                }
        }
    
        return ans;
    }
};