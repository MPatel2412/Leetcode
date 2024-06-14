class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        int ans = 0;
        for(int num : nums)
            max_val = max(max_val,num);
        
        vector<int> freq(n+max_val+1,0);
        for(int num : nums)
            freq[num]++;
        
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i] <= 1) continue;
            
            int duplicates = freq[i] - 1;
            freq[i+1] += duplicates;
            freq[i] = 1;
            ans += duplicates;
        }
        return ans;
    }
};