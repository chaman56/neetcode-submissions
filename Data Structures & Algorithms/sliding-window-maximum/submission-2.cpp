class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mx(n-k+1);
        priority_queue<int>pq;
        unordered_map<int, int>deleted;
        for(int i = 0; i<k; i++){
            pq.push(nums[i]);
        }
        mx[0] = pq.top();

        for(int i = k; i<n; i++){
            pq.push(nums[i]);
            deleted[nums[i-k]]++;
            while(deleted.contains(pq.top()) && deleted[pq.top()]>0){
                deleted[pq.top()]--;
                pq.pop();
            }
            mx[i-k+1] = pq.top();
        }
        return mx;
    }
};
