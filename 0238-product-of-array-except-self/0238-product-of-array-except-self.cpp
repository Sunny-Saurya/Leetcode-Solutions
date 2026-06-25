class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int mul1 = 1, mul2 = 1;

        for(int i = 0; i < n; i++){
            ans[i] = mul1;
            mul1 *= nums[i];
        }

        for(int i = n-1; i >= 0; i--){
            ans[i] *= mul2;
            mul2 *= nums[i];
        }
        return ans;
}
};