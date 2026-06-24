class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int l = 0, r = 0, n = nums.size();
        int count = 0;
        int mul = 1;
        while(r < n){
            mul *= nums[r];

            while(mul >= k){
                mul /= nums[l];
                l++;
            }
            count += (r -l + 1);
            r++;
        }
        return count;
    }   
};