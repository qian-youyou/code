class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, cnt = 0, maxn = 0;
        for(int i = 0; i < nums.size() - 1 && i <= cnt; ++i){
            if(nums[i] + i > maxn){
                maxn = nums[i] + i;
            }
            if(maxn >= nums.size() - 1){
                ++ans;
                break;
            }
            if(i == cnt){
                if(cnt != maxn){
                    ++ans;
                }
                cnt = maxn;
            }
        }
        return ans;
    }
};