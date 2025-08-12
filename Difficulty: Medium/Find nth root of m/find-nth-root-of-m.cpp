class Solution {
  public:
    int checkPow(int mid, int n, int m) {
       long long ans = 1;
       for(int i = 0; i < n; i++){
           ans = ans * mid;
           if(ans > m) return 2;
       }
       if(ans == m) return 1;
       else return 0;
    }
    int nthRoot(int n, int m) {
        // Code here
        int low = 0;
        int high = m;
        while(low <= high) {
            int mid = low + (high - low) /2;
            int midN = checkPow(mid, n, m);
            if(midN == 1) return mid;
            else if(midN == 0) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};