class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for(auto it : nums)
        {
            if(it < 0)
                neg.push_back(it);
            else
                pos.push_back(it);
        }
        int p=0,t=0;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(!flag)
            {
                nums[i] = pos[p++];
                flag = !flag;
            }
            else
            {
                nums[i] = neg[t++];
                flag = !flag;
            }
        }
        return nums;
    }
};