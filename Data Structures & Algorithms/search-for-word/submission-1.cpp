class Solution {
public:
    bool check(vector<vector<bool>>&vis, vector<vector<char>>& board, string& word, int idx, int i, int j){
        if(idx == word.size())return true;
        if(i<0 || i>=board.size())return false;
        if(j<0 || j>=board[0].size())return false;
        if(vis[i][j] || word[idx]!=board[i][j])return false;
        vis[i][j]=true;
        bool c = check(vis, board, word, idx+1, i, j+1) || check(vis, board, word, idx+1, i+1, j) || check(vis, board, word, idx+1, i-1, j) || check(vis, board, word, idx+1, i, j-1);
        vis[i][j]=false;
        return c;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(check(vis, board, word, 0, i, j))return true;
            }
        }
        return false;
    }
};
