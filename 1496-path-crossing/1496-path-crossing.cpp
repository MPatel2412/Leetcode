class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        set<pair<int,int>> s;
        int x= 0,y=0;
        s.insert({0,0});
        for(int i=0;i<n;i++)
        {
            if(path[i]=='N')
            {
                y++;
            }
            else if(path[i]=='S') 
                y--;
            else if(path[i]=='E')
                x++;
            else 
                x--;
            
            if(s.find({x,y})!=s.end())
                return true;
            else
                s.insert({x,y});
        }
        return false;
    }
};