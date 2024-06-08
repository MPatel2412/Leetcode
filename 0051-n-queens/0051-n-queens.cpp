class Solution {
public:
    void solve(int col,vector<string> &board, vector<vector<string>> &ans,int n,vector<int> left,vector<int> upDiag, vector<int> botDiag)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n;row++)
        {
            if(left[row]==0 && upDiag[row + col] == 0 && botDiag[col - row + n-1]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                upDiag[row + col] = 1;
                botDiag[col - row + n-1] = 1;
                solve(col+1,board,ans,n,left,upDiag,botDiag);
                board[row][col]='.';
                left[row]=0;
                upDiag[row + col] = 0;
                botDiag[col - row + n-1] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string >> ans;
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) 
        {
            board[i] = s;
        }
        vector<int> left(n,0);
        vector<int> upDiag(2*n-1,0);
        vector<int> botDiag(2*n-1,0);
        solve(0, board, ans, n,left,upDiag,botDiag);
        return ans;
    }
};