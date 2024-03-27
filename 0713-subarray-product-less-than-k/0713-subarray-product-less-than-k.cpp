class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int cnt = 0;
        int i = 0, j = 0;
        while(j<n)
        {
            product *= nums[j++];
            while(i < j && product >= k)
            {
                product /= nums[i++];
            }
            cnt += (j-i);
        }
        return cnt;
    }
};