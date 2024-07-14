class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        
        int hDiv = 1;
        int vDiv = 1;
        int cost = 0;

        priority_queue<pair<int, char>> pq;

        for(auto hc : hCut)
            pq.push({hc, 'h'});

        for(auto vc : vCut)
            pq.push({vc, 'v'});

        while(!pq.empty())
        {
            int cutCost = pq.top().first;
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