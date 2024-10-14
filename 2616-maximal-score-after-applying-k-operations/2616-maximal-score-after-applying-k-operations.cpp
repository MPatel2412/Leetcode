class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq;
        for(auto it : nums)
        {
            pq.push(it);
        }   
        while(k-- && !pq.empty())
        {
            int val = pq.top();
            pq.pop();
            score += (long long)val;
            pq.push(ceil(val/3.0));
        }
        return score;
    }
};