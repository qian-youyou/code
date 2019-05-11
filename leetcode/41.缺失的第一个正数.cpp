class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size(), i;
        for(i = 0; i < len; ++i){
            while(i < len && nums[i] != i + 1){
                if(nums[i] <= i || nums[i] > len || nums[i] == nums[nums[i] - 1]){
                    swap(nums[i], nums[len - 1]);
                    --len;
                }else{
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        if(i > len){
            --i;
        }
        return i + 1;
    }
};