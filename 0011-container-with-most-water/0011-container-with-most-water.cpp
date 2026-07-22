class Solution {
public:
    int maxArea(vector<int>& height) {

        // BRute force.. which will give TLE because of O(n^2) TC.
        // int n = height.size();
        // int maxi = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         int minHeight = min(height[i], height[j]);
        //         int area = minHeight * (j - i);
        //         maxi = max(maxi, area);
        //     }
        // }

        // return maxi;


        // Optimisation

        int n = height.size();
        int l = 0, r = n-1, maxi = 0;
    
        while(r < n && l < r){
            int minHeight = min(height[l], height[r]);
            int area = minHeight * (r - l);
            
            if(height[l] < height[r]){
                l++;
            }
            else if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
            maxi = max(maxi, area);

        }

        return maxi;


    }
};