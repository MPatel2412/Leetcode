class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i = 2*n - 1; i>=0;i--)
        {
            int index = i%n;
            while(!st.empty() && nums[st.top()] <= nums[index])
            {
                st.pop();
            }
            ans[index] = st.empty() ? -1 : nums[st.top()];
            st.push(index);
        }
        return ans;
        
    }
};