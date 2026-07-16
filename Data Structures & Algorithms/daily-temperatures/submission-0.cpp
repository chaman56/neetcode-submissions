class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int, int>> st;
        vector<int>result(n, 0);
        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top().first<t[i]){
                result[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({t[i], i});
        }
        return result;
    }
};
