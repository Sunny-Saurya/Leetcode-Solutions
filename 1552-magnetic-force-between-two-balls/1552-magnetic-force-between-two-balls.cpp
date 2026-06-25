class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1;
        int r = *max_element(position.begin(), position.end());
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(solve(position, m, mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
            
        }
        return ans;
    }

    bool solve(vector<int>&arr, int m, int mid){
        int last = arr[0];
        int mag = 1;

        for(int i = 1; i < arr.size(); i++){
            if(last + mid <= arr[i]){
                mag++;
                last = arr[i];
            }
        }

        return mag >= m;
    }
};