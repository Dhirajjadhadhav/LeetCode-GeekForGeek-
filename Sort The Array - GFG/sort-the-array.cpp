//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void merge(vector<int>&arr, int p, int q, int r)
    {
        int n1 = q-p+1;
        int n2 = r-q;
        int i,j,k;
        
        vector<int>a1(n1);
        vector<int>a2(n2);
        
        for(i = 0; i<n1; ++i)
            a1[i] = arr[p+i];
        
        
        for(i = 0; i<n2; ++i)
            a2[i] = arr[q+i+1];
            
        i = 0;
        j = 0;
        k = 0;
        
        while(1)
        {
            if(a1[i]<=a2[j])
            {
                
                arr[p+k] = a1[i];
                ++i;
                ++k;
                
                if(i==n1)
                {
                    while(j<n2)
                    {
                        arr[p+k] = a2[j];
                        ++k;
                        ++j;
                    }
                    break;
                }
            }
            else
            {
                arr[p+k] = a2[j];
                ++k;
                ++j;
                if(j == n2)
                {
                    while(i<n1)
                    {
                        arr[p+k] = a1[i];
                        ++k;
                        ++i;
                    }
                    break;
                }
            }
        }
        
    }
    void merge_sort(vector<int>&arr, int p, int r)
    {
        if(p<r)
        {
            int q = (p+r)/2;
            merge_sort(arr, p, q);
            merge_sort(arr, q+1, r);
            merge(arr, p, q, r);
        }
    }
    public:
    vector<int> sortArr(vector<int>arr, int n){
        merge_sort(arr, 0, n-1);
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends