
#include <bits/stdc++.h>
using namespace std;



class Solution {
    bool solve(int n, vector<int>&arr, int sum, vector<vector<int>>&memo){
         if(sum == 0)return true;
        if(n<=0)return false;
        
        if(memo[n][sum] != -1)return memo[n][sum];
        
        if(sum<arr[n-1])
            return memo[n][sum] = solve(n-1, arr, sum, memo);
        else
            return memo[n][sum]= solve(n-1, arr, sum, memo) || solve(n-1, arr, sum-arr[n-1], memo);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>memo(n+1,vector<int>(sum+1, -1));
        return solve(n, arr, sum, memo);
        
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends