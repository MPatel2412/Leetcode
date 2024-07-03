class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4)
            return 0;
        sort(nums.begin(),nums.end());

        int l = 3;
        int r = 0;
        int ans = INT_MAX;
        while (r <= 3) {
            int maxNum = nums[n - 1 - r];
            int minNum = nums[l];
            ans = min(maxNum - minNum, ans);
            l--;
            r++;
        }

        return ans;

    }
};