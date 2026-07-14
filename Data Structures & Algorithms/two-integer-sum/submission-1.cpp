class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;
        for(int i = 1;i<nums.size(); i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return vector<int>{mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return vector<int>();
    }
};
