//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution//prims algo
// {
// 	public:
// 	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         int ans=0;
//         vector<int> key(V,INT_MAX);
//         vector<bool> mst(V,false);
//         vector<int>parent(V,-1);
//         //let take source node as 0
//         key[0]=0;
//         parent[0]=-1;
//         for(int i=0;i<V;i++){//run total V times
//             int mini=INT_MAX;
//             int u;
//             //find min node
//             for(int i=0;i<V;i++){
//                 if(mst[i]==false && key[i]<mini){//not in bst and less then mini
//                     u=i;
//                     mini=key[i];  
//                 }
//             }
//             //mark min node as true
//             mst[u]=true;
//             //check its adjacent nodes
//             for(auto i:adj[u]){
//                 int v=i[0];
//                 int w=i[1];
//                 if(mst[v]==false && w<key[v]){
//                     parent[v]=u;
//                     key[v]=w;
//                 }
//             }
//         }
//         for(int i=0;i<V;i++){
//             ans+=key[i];
//         }
//         return ans;
//     }
// };




class Solution//kruskal algo
{
	public:
	void makeset(vector<int>& parent,vector<int>& rank,int V){
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
	}
	int findparent(vector<int>& parent,int node){
	    if(parent[node]==node){
	        return node;
	    }
	    return parent[node]=findparent(parent,parent[node]); //path compression
	}
	void unionset(int u, int v,vector<int>& parent,vector<int>& rank){
	    u=findparent(parent,u);
	    v=findparent(parent,v);
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
	    else if(rank[u]>rank[v]){
	        parent[v]=u;
	    }
	    else{//both equal
	        parent[v]=u;
	        rank[u]++;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int wt=it[1];
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end()); //bydefault sort with index 0
        
        vector<int> parent(V);
        vector<int> rank(V);
        makeset(parent,rank,V);
        
        int minweight=0;
        for(auto i:edges){
            int u=findparent(parent,i.second.first);
            int v=findparent(parent,i.second.second);
            int w=i.first;
            if(u!=v){
                minweight+=w;
                unionset(u,v,parent,rank);
            }
        }
        return minweight;
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