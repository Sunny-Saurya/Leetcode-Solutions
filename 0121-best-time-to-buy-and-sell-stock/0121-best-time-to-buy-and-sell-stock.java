class Solution {
    public int maxProfit(int[] prices) {
        int maxi = 0;
        int currPrice = prices[0];

        for(int i = 0; i < prices.length; i++){
            if(prices[i] < currPrice) currPrice = prices[i];
            else{
                int profit = prices[i] - currPrice;
                maxi = Math.max(maxi, profit);
            }
        }
        return maxi;
    }
}