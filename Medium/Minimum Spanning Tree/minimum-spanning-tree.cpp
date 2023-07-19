//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int>parent(V,-1);
        //let take source node as 0
        key[0]=0;
        parent[0]=-1;
        for(int i=0;i<V;i++){//run total V times
            int mini=INT_MAX;
            int u;
            //find min node
            for(int i=0;i<V;i++){
                if(mst[i]==false && key[i]<mini){//not in bst and less then mini
                    u=i;
                    mini=key[i];  
                }
            }
            //mark min node as true
            mst[u]=true;
            //check its adjacent nodes
            for(auto i:adj[u]){
                int v=i[0];
                int w=i[1];
                if(mst[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                }
            }
        }
        for(int i=0;i<V;i++){
            ans+=key[i];
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