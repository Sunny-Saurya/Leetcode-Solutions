class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin = 0, total = 0;

        for (int x : nums) {
            currMax = max(currMax + x, x);
            currMin = min(currMin + x, x);

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);

            total += x;
        }

        if (globalMax < 0)
            return globalMax;

        return max(globalMax, total - globalMin);
    }
};