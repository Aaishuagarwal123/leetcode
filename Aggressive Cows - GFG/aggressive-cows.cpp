//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
   bool isTrue(vector<int> &nums,int n,int k,int mid)
   {
       int temp=nums[0];
       int cow=1;
       for(int i=1;i<n;i++)
       {
           if(nums[i]-temp>=mid)
           {
               cow++;
               temp=nums[i];
           }
       }
       return (cow>=k);
   }
    int solve(int n, int k, vector<int> &nums) {
    
        // Write your code here
        int low=1;
        
        sort(nums.begin(),nums.end());
        int high=nums[n-1]-nums[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isTrue(nums,n,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends