class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }
        dfs(board);
    }
private:
    void check(vector<vector<char>>& v, int x, int y, set<char>& s){
        for(int i = 0; i < v.size(); ++i){
            s.insert(v[i][x]);
            s.insert(v[y][i]);
            s.insert(v[y - (y % 3) + (i / 3)][x - (x % 3) + (i % 3)]);
        }
    }
    bool dfs(vector<vector<char>>& v){
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v.size(); ++j){
                if(v[i][j] == '.'){
                    set<char>s;
                    check(v, j, i, s);
                    for(char k = '1'; k <= '9'; ++k){
                        if(s.count(k) > 0){
                            continue;
                        }
                        v[i][j] = k;
                        if(dfs(v)){
                            return true;
                        }
                    }
                    v[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
};