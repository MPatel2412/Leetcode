class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Map to maintain sorted frequency map of current window
        map<int, int> freq;
        int left = 0, right = 0;
        int n = nums.size();
        long long count = 0;  // Total count of valid subarrays

        while (right < n) 
        {
            freq[nums[right]]++;

            
            while (freq.rbegin()->first - freq.begin()->first > 2)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }
};