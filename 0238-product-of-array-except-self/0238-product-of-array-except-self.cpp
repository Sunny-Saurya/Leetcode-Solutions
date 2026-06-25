class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxR(n), maxL(n);
        maxRight(maxR, nums);
        maxLeft(maxL, nums);
        for(auto num : maxR) cout << num << " ";
        cout << endl;
        for(auto num : maxL) cout << num << " ";
        vector<int>ans;

        for(int i = 0; i < n; i++){
            long long mul = maxR[i] * maxL[i];
            ans.push_back(mul);
        }

        return ans;
        
    }

    void maxRight(vector<int>&maxR, vector<int>&nums){
        int n = nums.size();

        int mul = 1;
        maxR[n-1] = mul;

        for(int i = n-2; i >= 0; i--){
            maxR[i] = nums[i+1]*mul;
            mul = maxR[i];
        }
    }

    void maxLeft(vector<int>&maxL, vector<int>&nums){
        int n = nums.size();

        int mul = 1;
        maxL[0] = mul;

        for(int i = 1; i < n; i++){
            maxL[i] = nums[i-1]*mul;
            mul = maxL[i];
        }
    }
};