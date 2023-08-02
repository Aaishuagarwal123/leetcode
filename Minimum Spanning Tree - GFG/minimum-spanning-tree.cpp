//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	unordered_map<int,int> par;
	unordered_map<int,int> rank;
	int findpar(int node)
	{
	    if(par[node]==node)
	    return node;
	    return par[node]=findpar(par[node]);
	}
	void unionn(int u,int v)
	{
	    u=findpar(u);
	    v=findpar(v);
	    if(u==v)
	    return;
	    if(rank[u]>rank[v])
	    par[v]=u;
	    else if(rank[v]>rank[u])
	    par[u]=v;
	    else
	    {
	       par[v]=u;
	       rank[u]++;
	    }
	}

    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
    //     vector<vector<int>> edges;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(auto v:adj[i])
    //         {
    //             int dest=v[0];
    //             int wt=v[1];
    //           edges.push_back({wt,i,dest});
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         par[i]=i;
    //         rank[i]=0;
    //     }
    //   sort(edges.begin(),edges.end());
    //   int ans=0;
    //   for(int i=0;i<edges.size();i++)
    //   {
    //       int u=edges[i][1];
    //       int v=edges[i][2];
    //       int wt=edges[i][0];
    //       if(findpar(u)!=findpar(v))
    //       {
    //           unionn(u,v);ans+=wt;
    //       }
    //   }
    //   return ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int> vis(n,0);
    pq.push({0,0});
    int ans=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        if(vis[node])
        continue;
        vis[node]=1;
        ans+=wt;
        for(auto u:adj[node])
        {
            //if(!vis[u[0]])
            pq.push({u[1],u[0]});
        }
        
    }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends