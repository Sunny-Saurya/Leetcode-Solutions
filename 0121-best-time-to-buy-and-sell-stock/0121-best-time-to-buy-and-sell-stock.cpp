class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currPrice = prices[0];
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < currPrice) currPrice = prices[i];
            else{
                int profit = prices[i] - currPrice;
                maxi = max(maxi, profit);
            }
        
        }

        return maxi;
    }
};