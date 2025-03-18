//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool solve(int n, vector<int>&arr, long long sum, vector<vector<int>>&memo){
        if(sum == 0)
            return true;
        if(n<=0)
            return false;
        if(memo[n][sum] != -1)
            return memo[n][sum];
        if(sum<arr[n-1])
            return memo[n][sum] = solve(n-1, arr, sum, memo);
    
        return memo[n][sum] = solve(n-1, arr, sum-arr[n-1], memo) 
                    || solve(n-1, arr, sum, memo);
    }
  public:
    bool equalPartition(vector<int>& arr) {
        
        int n = arr.size();
        long long sum = accumulate(arr.begin(), arr.end(), 0LL);
        if(sum&1)return false;
        vector<vector<int>>memo(n+1, vector<int>(sum/2 +1, -1));
        return solve(n, arr, sum/2,memo);
        
    }
};


//{ Driver Code Starts.

int main() {
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends