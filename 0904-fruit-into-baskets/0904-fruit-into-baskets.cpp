class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, k = 2;
        unordered_map<int,int>mpp;
        int maxi = 0;

        while(r < n){
            int val = fruits[r];
            mpp[val]++;
            if(mpp.size() > k){
                while(mpp.size() > k){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }

            }
                maxi = max(maxi, r - l+1);
                r++;
        }
        return maxi;
    }
};