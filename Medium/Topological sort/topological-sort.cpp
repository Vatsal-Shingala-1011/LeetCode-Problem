//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution
// {
// 	public:
// 	void topological(int node,unordered_map<int,bool>& visited,stack<int>& s,vector<int>*& adj){
// 	    visited[node]=true;
// 	    for(auto neighbour: adj[node]){
// 	        if(!visited[neighbour]){
// 	            topological(neighbour,visited,s,adj);
// 	        }
// 	    }
// 	    s.push(node);
// 	}
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    unordered_map<int,bool> visited;
// 	    stack<int>s;
// 	    //call dsf for all components
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
// 	            topological(i,visited,s,adj);
// 	        }
// 	    }
// 	    vector<int>ans;
// 	    while(!s.empty()){
// 	        ans.push_back(s.top());
// 	        s.pop();
// 	    }
// 	    return ans;
// 	}
// };

class Solution//kahn's algorithm
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        //find all indegress
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
	//push 0 indegree
	queue<int> q;
	
	for(int k=0;k<V;k++){
	    if(indegree[k]==0) q.push(k);
	}
	// do bsf
	vector<int> ans;
	while(!q.empty()){
	    int front=q.front();
	    q.pop();
	    //ans store
	    ans.push_back(front);
	    //neighbour indegree --
	    for(auto neighbour: adj[front]){
	        indegree[neighbour]--;
	        if(indegree[neighbour]==0) q.push(neighbour);
	    }
	}
	return ans;
	}
};













//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends