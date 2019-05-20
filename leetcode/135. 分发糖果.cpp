class Solution {
public:
    int candy(vector<int>& ratings) {
        val.resize(ratings.size(), 0);
        ans = 0;
        for(int i = 0; i < ratings.size(); ++i){
            if(i == 0 || ratings[i] <= ratings[i - 1]){
                val[i] = 1;
            }else{
                val[i] = val[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1]){
                val[i] = max(val[i], val[i + 1] + 1);
            }
        }
        for(int i = 0; i < ratings.size(); ++i){
            ans += val[i];
        }
        return ans;
    }
private:
    vector<int>val;
    int ans;
};