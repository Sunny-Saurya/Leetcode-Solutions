class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = candidates.size();
        solve(0, candidates, target, ans, temp);

        return ans;
    }

    void solve(int idx, vector<int>& arr, int target, vector<vector<int>>& ans,
               vector<int>& temp) {

        // base case

        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;

        if (idx == arr.size()) {
            return;
        }

        // take
        temp.push_back(arr[idx]);
        solve(idx, arr, target - arr[idx], ans, temp);
        temp.pop_back();
        solve(idx + 1, arr, target, ans, temp);
    }
};