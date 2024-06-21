class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(!grumpy[i]) res+=customers[i];
        }
        int curr = 0, maxi = 0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i])
                curr+=customers[i];
        }
        int l = 0;
        maxi = max(maxi,curr);
        for(int i=minutes;i<n;i++)
        {
            if(grumpy[i])
            {
                curr+=customers[i];
            }
            if(grumpy[l])
            {
                curr-=customers[l];
            }
            l++;
            maxi = max(maxi,curr);
        }
        return maxi + res;
    }
};