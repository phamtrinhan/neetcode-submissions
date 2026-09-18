class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProfit = 0;

        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[left]) 
                left = right;
            else {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};