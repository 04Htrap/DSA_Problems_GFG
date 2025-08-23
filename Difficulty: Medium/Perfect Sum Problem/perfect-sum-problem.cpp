class Solution {
  public:
    int returnWays(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(idx == 0) {
            if(target == 0 && arr[0] == 0) return 2;  // take or not take
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int not_take = returnWays(idx - 1, arr, target, dp);
        int take = 0;
        if(arr[idx] <= target) {
            take = returnWays(idx - 1, arr, target - arr[idx], dp);
        }
        
        return dp[idx][target] = take + not_take;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, - 1));
        
        return returnWays(n- 1, arr, target, dp);
    }
};