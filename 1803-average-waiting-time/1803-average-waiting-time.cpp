class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        long long waiting = 0;
        long long time = customers[0][0];
        for(int i=0; i < customers.size(); i++)
        {
            if(time < customers[i][0])
            {
                //waiting += (customers[i][0] - time);
                time = customers[i][0];
            }
            waiting += customers[i][1] + time - customers[i][0];
            time += customers[i][1];
        }
        ans = (double)(waiting/(double)customers.size());
        return ans;
    }
};