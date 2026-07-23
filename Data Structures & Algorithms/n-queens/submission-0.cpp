class Solution {
public:
    vector<vector<string>>res;
    bool check(vector<string>&temp, int i, int j){
        for(int r = i-1; r>=0; r--){
            if(temp[r][j]=='Q')return false;
            if(j-(i-r)>=0 && temp[r][j-i+r]=='Q')return false;
            if(j+(i-r)<temp.size() && temp[r][j+i-r]=='Q')return false;
        }
        return true;
    }
    void solve(int n, vector<string>&temp, int i){
        if(i==n){
            res.push_back(temp);
            return;
        }
        for(int j = 0; j<n; j++){
            if(!check(temp, i, j))continue;
            temp[i][j]='Q';
            solve(n, temp, i+1);
            temp[i][j]='.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string>temp(n, s);
        solve(n, temp, 0);
        return res;
    }
};
