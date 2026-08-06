class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(), nums.end());
        set<int>s(nums.begin(), nums.end());
        int left = nums[0];
        int right = nums[n-1];

        for(int i = left; i <= right; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};