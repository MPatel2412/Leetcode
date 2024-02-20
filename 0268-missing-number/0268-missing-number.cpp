class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=index)
            {
                break;
            }
            index++;
        }
        return index;
    }
};