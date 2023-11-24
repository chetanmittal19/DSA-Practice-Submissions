class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int curr_min = prices[0];
        for(int i = 1; i<prices.length; i++){
            if(curr_min>prices[i]){
                curr_min = prices[i];
            } else maxProfit = Math.max(maxProfit, prices[i]-curr_min);
        }
        return maxProfit;
    }
}