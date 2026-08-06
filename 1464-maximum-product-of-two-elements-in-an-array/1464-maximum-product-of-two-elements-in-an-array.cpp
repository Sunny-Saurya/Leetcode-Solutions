class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = 1;
        int n  = nums.size();
        int mul = 1;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                mul = (nums[i]-1) * (nums[j] -1);
                maxi = max(maxi, mul);
            }
        }
        return maxi;

    }
};