//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {

        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents overflow

            if (arr[mid] == k) {
                return true; // Element found
            } 
            else if (arr[mid] < k) {
                left = mid + 1; // Search in the right half
            } 
            else {
                right = mid - 1; // Search in the left half
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << (ob.searchInSorted(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends