class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0,maxi = 0, zero = 0;

        while(r < n){
            if(nums[r] == 0){
                zero++;
                while(zero > k){
                    int val = nums[l];
                    if(val == 0){
                        zero--;
                    }
                    l++;
                }
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};