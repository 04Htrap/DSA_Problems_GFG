class Solution {
  public:
  
    int power(int base, int expo) {
        int res = 1;
        
        for(int i = 0; i < expo; i++)
            res *= base;
        return res;
    }
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0) return 0;
        if(n == 1) return m;
        
        int low = 0;
        int high = m;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int val = power(mid, n);
            if(val == m)
                return mid;
            else if(val > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};