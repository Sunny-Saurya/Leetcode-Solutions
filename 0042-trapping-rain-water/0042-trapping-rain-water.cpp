class Solution {
    vector<int>prefix, suffix;

    void prefixMax(vector<int>&height){
        int n = height.size();
        prefix.assign(n, 0);
        prefix[0] = height[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
    }

    void suffixMax(vector<int>&height){
        int n = height.size();
        suffix.assign(n, 0);
        suffix[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        prefixMax(height);
        suffixMax(height);

        int totalWaterTrapped = 0;
        for(int i = 0; i < n; i++){
            if(prefix[i] == 0|| suffix[i] == 0) continue;
            int waterCap = min(prefix[i], suffix[i]);
            if(waterCap > height[i]){
                totalWaterTrapped += waterCap - height[i];
            }
        }
        return totalWaterTrapped;
    }
};