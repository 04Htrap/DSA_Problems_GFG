class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size(), -1);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i = 2; i < height.size(); i++) {
            int jump1step = dp[i - 1] + abs(height[i] - height[i - 1]);
            int jump2step = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(jump1step, jump2step);
        }
        
        return dp[height.size()- 1];
    }
};