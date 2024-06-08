class Solution {
public:
    bool func(vector<vector<char>> &board,string word,int i,int j,int index,int m,int n)
    {
        //base condition
        if(index == word.size())
            return true;
        
        if(i <0 || j <0 || i>=m || j >= n || board[i][j] != word[index] || board[i][j] == '!')
            return false;
        
        char c = board[i][j];
        board[i][j]='!';
        
        bool top = func(board,word,i-1,j,index+1,m,n);
        bool down = func(board,word,i+1,j,index+1,m,n);
        bool left = func(board,word,i,j-1,index+1,m,n);
        bool right = func(board,word,i,j+1,index+1,m,n);
        
        board[i][j]=c;
        
        return top || down || left || right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[index])
                {
                    if(func(board,word,i,j,index,m,n))
                        return true;
                }
            }
        }
        return false;
    }
};