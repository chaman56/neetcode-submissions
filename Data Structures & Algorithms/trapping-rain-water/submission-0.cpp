class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmx(n), rmx(n);
        int mx = 0;
        for(int i = 0; i<n; i++){
            mx = max(mx, height[i]);
            lmx[i] = mx;
        }
        mx = 0;
        for(int j = n-1; j>=0; j--){
            mx = max(mx, height[j]);
            rmx[j] = mx;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int mn = min(lmx[i], rmx[i]);
            if(height[i]<mn)
                ans += mn-height[i];
        }
        return ans;
    }
};
