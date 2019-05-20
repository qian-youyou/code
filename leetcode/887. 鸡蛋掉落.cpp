class Solution {
public:
    int superEggDrop(int K, int N) {
        dp.resize(2, vector<long long>(N + 1, 0));
        int flag = 0, i, j;
        for(i = 1; i <= K; ++i){
            for(j = 1; j <= N && dp[flag][j] < N; ++j){
                dp[flag][j] = dp[flag^1][j - 1] + dp[flag][j - 1] + 1;
                if(dp[flag][j] >= N){
                    break;
                }
            }
            flag ^= 1;
        }
        return j;
    }
private:
    vector<vector<long long> >dp;
};