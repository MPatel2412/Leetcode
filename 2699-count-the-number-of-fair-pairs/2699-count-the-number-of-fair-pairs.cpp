class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i < n; i++)
        {
            auto upper_index = upper_bound(nums.begin() + i + 1,nums.end(),upper - nums[i]);
            auto lower_index = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);

            ans += (upper_index - lower_index);
        }
        return ans;
    }
};