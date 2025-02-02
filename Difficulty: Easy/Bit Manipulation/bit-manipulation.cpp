//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        if (i < 0 || i >= 32) {
            cout << "Error: Bit index out of range (0-31)" << endl;
            return;
        }
        i--;
        int get_ith = (num >> i) & 1;
            
        int set_ith = num | (1 << i);
        
        int clear_ith = num & (~(1 << i));
        
        cout << get_ith <<" ";
        cout << set_ith << " ";
        cout << clear_ith << " ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends