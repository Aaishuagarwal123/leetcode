//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    unordered_set<int> vis;
    bool helper(int par,int node,vector<int> adj[])
    {
      vis.insert(node);
      for(auto u:adj[node])
      {
          if(vis.find(u)==vis.end())
          {
              if(helper(node,u,adj))
              return true;
          }
          else
          {
              if(u!=par)
              return true;
          }
      }
      return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
       
    for(int i=0;i<n;i++)
    {
      if(vis.find(i)!=vis.end())
      continue;
      if(helper(-1,i,adj))
      return true;
    }
    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends