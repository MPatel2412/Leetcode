class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(auto it : nums)
            cnt+=it;
        
        vector<int> temp(2*n);
        for(int i=0; i < 2*n; i++)
        {
            temp[i] = nums[i%n];
        }
        int co=0;
        int cz=0;
        int swaps = INT_MAX;
        int i=0, j =0;
        for(j=0; j < cnt; j++)
        {
            if(temp[j] == 0)
                cz++;
            else
                co++;
        }
        swaps = min(swaps, cz);
        for(j=cnt; j < 2*n; j++)
        {
            if(temp[i++] == 0)
                cz--;
            else
                co--;
            
            if(temp[j] == 0)
                cz++;
            else
                co++;

            swaps = min(swaps, cz);
        }

        return swaps;
    }
};