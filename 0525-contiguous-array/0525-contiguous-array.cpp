class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(2*n+1,-2);
        arr[n] = -1;
        int maxi=0,cnt = 0;
        for(int i=0;i<n;i++)
        {
            cnt += (nums[i] == 0 ? -1 : 1);
            if(arr[cnt + n] >= -1)
            {
                maxi = max(maxi,i-arr[cnt+n]);
            }
            else
            {
                arr[n+cnt] = i;
            }
        }
        return maxi;
    }
};