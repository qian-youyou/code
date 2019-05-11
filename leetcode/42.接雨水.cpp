class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i = 0; i < height.size(); ++i){
            int tmp = 0;
            while(!stk.empty() && height[i] >= stk.top().first){
                ans += (stk.top().first - tmp) * (i - stk.top().second - 1);
                tmp = stk.top().first;
                stk.pop();
            }
            if(!stk.empty()){
                ans += (height[i] - tmp) * (i - stk.top().second - 1);
            }
            stk.push(make_pair(height[i], i));
        }
        while(!stk.empty()){
            stk.pop();
        }
        return ans;
    }
private:
    stack<pair<int, int> >stk;
};