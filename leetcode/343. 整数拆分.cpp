class Solution {
public:
    int integerBreak(int n) {
        init();
        return v[n];
    }
private:
    void init(){
        v.resize(59, 0);
        v[1] = 1;
        for(int i = 1; i < v.size(); ++i){
            for(int j = 1; j < i; ++j){
                v[i] = max(max(v[j], j) * max(v[i - j], (i - j)), v[i]);
            }
        }
    }
    vector<int>v;
};