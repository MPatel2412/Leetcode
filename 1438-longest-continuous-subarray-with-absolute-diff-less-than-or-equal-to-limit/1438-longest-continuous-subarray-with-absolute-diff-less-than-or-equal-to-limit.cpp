class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> curr;
        int l = 0, maxi = 0;
        for(int r=0;r < nums.size(); r++)
        {
            curr.insert(nums[r]);
            while(l < r && *curr.rbegin() - *curr.begin() > limit)
            {
                curr.erase(curr.find(nums[l]));
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};