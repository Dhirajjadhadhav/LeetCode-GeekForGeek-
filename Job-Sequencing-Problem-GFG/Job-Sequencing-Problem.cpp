//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>>jobs;
        
        for(int i = 0; i<n; ++i)
            jobs.push_back({deadline[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(const auto& job : jobs)
        {
            if(job.first > pq.size())
                pq.push(job.second);
            else if(!pq.empty() && job.second > pq.top())
            {
                pq.pop();
                pq.push(job.second);
            }
        }
        vector<int>res= {0, 0};
        while(!pq.empty())
        {
           res[1] += pq.top();
           pq.pop();
           res[0]++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends