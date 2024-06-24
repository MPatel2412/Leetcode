class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> st;
        vector<int> graph[numCourses];
        vector<int> inDegree(numCourses,0);
        for(auto course : prerequisites)
        {
            graph[course[1]].push_back(course[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            for(auto node : graph[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            cnt++;
            for(auto adj : graph[node])
            {
                inDegree[adj]--;
                if(inDegree[adj] == 0)
                    q.push(adj);
            }
        }
        if(cnt == numCourses)
            return true;
        
        return false;
        
        
    }
};