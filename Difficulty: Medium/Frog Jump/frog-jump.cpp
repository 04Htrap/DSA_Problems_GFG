//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int jump_one = dp[i - 1] + abs(height[i] - height[i - 1]);
            int jump_two = INT_MAX;
            if(i > 1){
                jump_two = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(jump_one, jump_two);
        }
        
        return dp[n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends