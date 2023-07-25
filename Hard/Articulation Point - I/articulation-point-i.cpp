//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,int parent,vector<int>&disc, vector<int>& low,unordered_map<int,bool>& visited,vector<int>*& adj,vector<bool>& ap,int& timer){
        visited[node]=true;
        disc[node]=low[node]=timer++;
        int child=0;
        for(auto nbr: adj[node]){
            if(nbr==parent) continue;
            if(!visited[nbr]){
                dfs(nbr,node,disc,low,visited,adj,ap,timer);
                low[node]=min(low[node],low[nbr]);
                //check for AP
                if(low[nbr]>=disc[node] && parent !=-1){
                    ap[node]=true;
                }
                child++;
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
            if(parent == -1 && child>1){
                ap[node]=true;
            }
        }
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer=0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool> ap(V,0);
        unordered_map<int,bool> visited;
        vector<int> ans;
        for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,-1,disc,low,visited,adj,ap,timer);
           }
            
        }
        for(int i=0;i<V;i++){
            if(ap[i]){
                ans.push_back(i);
            }
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends