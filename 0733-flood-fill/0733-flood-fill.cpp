class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},image[sr][sc]});
        int row[] = {0,1,0,-1};
        int col[] = {1,0,-1,0};
        while(!q.empty())
        {
            auto node = q.front();
            int x = node.first.first;
            int y = node.first.second;
            int og = node.second;
            q.pop();
            vis[x][y] = 1;
            image[x][y] = color;
            for(int i=0;i<4;i++)
            {
                int r = x + row[i];
                int c = y + col[i];

                if(r>=0 && c>=0 && r < m && c < n && !vis[r][c] && og == image[r][c])
                {
                    q.push({{r,c},og});
                }
            }
        }
        return image;
    }
};