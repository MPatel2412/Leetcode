class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        map<int,int> mpp;
        int prefixMod = 0;
        mpp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            prefixMod = (prefixMod + nums[i] % k + k) % k;
            cnt += mpp[prefixMod];
            mpp[prefixMod]++;
        }
        return cnt;
    }
};