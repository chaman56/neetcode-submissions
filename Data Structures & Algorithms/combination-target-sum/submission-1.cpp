class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>& nums, int target, int i, vector<int>cur){
        if(target==0){
            res.push_back(cur);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (target - nums[j] < 0) {
                return;
            }
            cur.push_back(nums[j]);
            dfs(nums, target - nums[j], j, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0, {});
        return res;
    }
};
