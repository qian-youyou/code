class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        init(matrix.size(), matrix[0].size());
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                max_num = max(max_num, dfs(matrix, j, i, 0x3f3f3f3f));
            }
        }
        return max_num;

    }
private:
    void init(int len_1, int len_2){
        dp.resize(len_1, vector<int>(len_2, 0));
        max_num = 0;
    }
    int dfs(vector<vector<int>>& v, int x, int y, int num){
        if(x < 0 || x >= v[0].size() || y < 0 || y >= v.size() || v[y][x] >= num){
            return 0;
        }
        if(dp[y][x]){
            return dp[y][x];
        }
        for(int i = 0; i < 4; ++i){
            dp[y][x] = max(dp[y][x], dfs(v, x + dir[i][1], y + dir[i][0], v[y][x]) + 1);
        }
        return dp[y][x];
    }
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int max_num;
    vector<vector<int>>dp;
};
