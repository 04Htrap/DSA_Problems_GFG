class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i = 0; i < m; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n - 1]);
        }
        
        int min_req = (n * m) / 2;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            
            for(int i = 0; i < m; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            if(cnt <= min_req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
