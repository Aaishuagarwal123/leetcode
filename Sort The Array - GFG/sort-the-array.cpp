//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int part(vector<int>&arr,int s,int e)
    {
        int pivot=arr[s];
        int cnt=0;
        for(int i=s+1;i<=e;i++)
        {
            if(arr[i]<=pivot)
            cnt++;
        }
        int pi=s+cnt;
        swap(arr[pi],arr[s]);
        int i=s;int j=e;
        while(i<pi&&j>pi)
        {
            while(i<pi&&arr[i]<=pivot)
            {
                i++;
            }
            while(j>pi&&arr[j]>pivot)
            {
                j--;
            }
            if(i<pi&&j>pi)
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        return pi;
    }
    void qs(vector<int>&arr,int s,int e)
    {
        if(s>=e)
        return;
        int p=part(arr,s,e);
        qs(arr,s,p-1);
        qs(arr,p+1,e);
    }
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
    qs(arr,0,n-1);
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