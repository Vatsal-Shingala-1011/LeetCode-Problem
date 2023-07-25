//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int n=edges.size();
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){ //V-1 time loop
            //traverse on edges 
            for(int j=0;j<n;j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                
                if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        bool flag=0;
        //check for negative cycle
        for(int j=0;j<n;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
                
            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){//no need for dist[u]!=1e9 codition because every dis update atleast onces
                flag=1;
            }
        }
        if(flag) return {-1};
        vector<int> ans;
        for(int i=0;i<V;i++){
            ans.push_back(dist[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends