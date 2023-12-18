class Solution {
 public:
  int maxProductDifference(vector<int>& nums) {
    int max1 = nums[0];
    int max2 = nums[0];
    int min1 = nums[0];
    int min2 = nums[0];

    // for (const int num : nums) {
    //   if (num > max1) {
    //     max2 = max1;
    //     max1 = num;
    //   } else if (num > max2) {
    //     max2 = num;
    //   }
    //   if (num < min1) {
    //     min2 = min1;
    //     min1 = num;
    //   } else if (num < min2) {
    //     min2 = num;
    //   }
    // }
    sort(nums.begin(),nums.end());
    max1 = nums[nums.size()-1];
    max2 = nums[nums.size()-2];
    min1 = nums[0];
    min2 = nums[1];

    return max1 * max2 - min1 * min2;
  }
};