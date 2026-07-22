class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n), rightMax(n);
        prefixMax(height, leftMax);
        suffixMax(height, rightMax);

        int total = 0;
        for(int i = 0; i < height.size(); i++){
            if(leftMax[i] > height[i] && rightMax[i] > height[i])
                total += min(leftMax[i],  rightMax[i]) - height[i];
        }

        return total;
    }

    void prefixMax(vector<int>&arr, vector<int>&leftMax){
        leftMax[0] = arr[0];

        for(int i = 1; i < arr.size(); i++){
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
    }

    void suffixMax(vector<int>&arr, vector<int>&rightMax){
        rightMax[arr.size()-1] = arr[arr.size()-1];

        for(int i = arr.size()-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
    }
};