class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp.resize(nums.size(), vector<int>(nums.size(), 0));
        for(int i = 2; i < nums.size(); ++i){
            for(int j = 0; j + i < nums.size(); ++j){
                for(int k = j + 1; k < j + i; ++k){
                    dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k][j + i] + nums[k] * nums[j] * nums[j + i]);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }
private:
    vector<vector<int>>dp;
};