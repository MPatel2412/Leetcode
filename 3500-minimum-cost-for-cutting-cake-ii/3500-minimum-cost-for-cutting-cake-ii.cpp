class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        long long hDiv = 1;
        long long vDiv = 1;
        long long cost = 0;

        priority_queue<pair<long long, char>> pq;

        for(auto hc : hCut)
            pq.push({hc, 'h'});

        for(auto vc : vCut)
            pq.push({vc, 'v'});

        while(!pq.empty())
        {
            long long cutCost = pq.top().first;
            char cutDir = pq.top().second;
            pq.pop();

            if(cutDir == 'h')
            {
                cost += cutCost * vDiv;
                hDiv++;
            }
            else
            {
                cost += cutCost * hDiv;
                vDiv++;
            }
        }    
        return cost;
    }
};