class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int curr = 0;
        int left = 0, right = 0;
        unordered_map<char,int> mp;
        while(right < n)
        {
            char ch = s[right];
            if(mp.find(ch) != mp.end())
            {
                while(left < right && s[left] != ch)
                {
                    mp.erase(s[left]);
                    left++;
                    curr--;
                }
                left++;
                right++;
            }
            else
            {
                mp[ch]=1;
                curr++;
                right++;
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};