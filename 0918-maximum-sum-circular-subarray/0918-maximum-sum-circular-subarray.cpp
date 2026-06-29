class Solution {
public:
    int kadane(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int num : nums) {
            currSum = max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int normalMax = kadane(nums);

        if (normalMax < 0)
            return normalMax;

        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int &num : nums)
            num = -num;

        int maxNeg = kadane(nums);

        int circularMax = total + maxNeg;

        return max(normalMax, circularMax);
    }
};