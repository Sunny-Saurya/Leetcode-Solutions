class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int maxCurr = nums[0];
        int minCurr = nums[0];

        int r = 1;
        while(r < n){
            
            if(nums[r] < 0){
                swap(maxCurr, minCurr);
            }

            maxCurr = max(nums[r], maxCurr*nums[r]);
            minCurr = min(nums[r], minCurr*nums[r]);

            maxi = max(maxi, maxCurr);
            r++;

        }
        return maxi;
    }
};