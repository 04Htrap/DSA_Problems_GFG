class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort both arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int platforms_needed = 0;
        int max_platforms = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
                max_platforms = max(max_platforms, platforms_needed);
            } 
            else {
                platforms_needed--;
                j++;
            }
        }
        
        return max_platforms;
    }
};