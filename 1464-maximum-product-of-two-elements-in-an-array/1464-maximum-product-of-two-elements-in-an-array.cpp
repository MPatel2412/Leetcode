class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=0,second_largest=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] > largest)
            {
                second_largest = largest;
                largest = nums[i];
            }
            else
            {
                second_largest = max(second_largest,nums[i]);
            }
        }
        return (largest-1)*(second_largest-1);
    }
};