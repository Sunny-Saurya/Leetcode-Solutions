class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mini = INT_MAX;
        while(l <= r){
            int mid = l + (r - l)/2;
            mini = min(nums[mid], mini);
            if(nums[mid] < nums[r]){
                r = mid -1;
            }else{
                l = mid + 1;
            }

        }

        return mini;
    }
};