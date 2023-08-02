//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> vis;
    stack<int> st;
    void dfs(int i)
    {
        vis[i]=true;
        for(auto u:adj[i])
        {
            if(!vis[u])
            dfs(u);
        }
        st.push(i);
    }
    string findOrder(string dict[], int n, int k1) {
        //code here
        for(int i=0;i<n-1;i++)
        {
            string c=dict[i];
            string n=dict[i+1];
            for(int k=0;k<min(c.length(),n.length());k++)
            {
                if(c[k]!=n[k])
                {
                    adj[c[k]-'a'].push_back(n[k]-'a');
                    break;
                }
            }}
            string ans="";
            for(int i=0;i<k1;i++)
            {
                vis[i]=false;
            }
             for(int i=0;i<k1;i++)
            {
               if(!vis[i])
               dfs(i);
            }
            while(!st.empty())
            {
                ans.push_back(st.top()+'a');
                st.pop();
            }
            return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends