class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            long long total = solve(piles, h, mid);
            
            if(total <= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    long long solve(vector<int>&arr, int h, int mid){
        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            res += (arr[i]+mid-1)/mid;
        }

        return res;
    }
};