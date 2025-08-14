class Solution {
  public:
    int paintCount(vector<int>& arr, int mid, int k) {
        int painters = 1;
        int boardsPainted = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(boardsPainted + arr[i] <= mid) {
                boardsPainted += arr[i];
            }
            
            else {
                painters++;
                boardsPainted = arr[i];
            }
        }
        return painters;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int painters = paintCount(arr, mid, k);
            if(painters > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
        
    }
};