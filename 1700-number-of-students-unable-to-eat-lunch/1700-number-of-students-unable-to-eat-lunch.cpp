class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int index = 0;
        queue<int> q;
        for(auto i : students)
        {
            q.push(i);
        }
        int n = students.size();
        int cnt = 0;
        
        while(index < n && !q.empty())
        {
            if(cnt == q.size())
                break;
            int st = q.front();
            q.pop();
            if(st==sandwiches[index])
            {
                index++;
                cnt = 0;
            }
            else
            {
                cnt++;
                q.push(st);
            }
        }
        return q.size();
        
    }
};