class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int r = 0, n = nums.size()-1;
        int sum = 0, count = 0;
        unordered_map<int,int>mpp;
        mpp[0] = 1;

        while(r < nums.size()){
            sum += nums[r];
            int diff = sum - k;

            if(mpp.count(diff)){
                count += mpp[diff];
            }

            mpp[sum]++;
            r++;
        }

        return  count;
    }
};