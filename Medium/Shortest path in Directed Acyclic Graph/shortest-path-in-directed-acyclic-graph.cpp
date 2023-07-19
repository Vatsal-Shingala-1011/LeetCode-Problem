//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
    void dfs(int node, unordered_map<int,bool>& visited, stack<int>& s, unordered_map<int,list<pair<int,int>>>& adj){
        visited[node]=true;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,s,adj);
            }
        }
        s.push(node);
    }                             // node,edges
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>> adj;
                    //u ,           v, weight
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        //topological sort
        unordered_map<int,bool> visited;
        stack<int> s;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,visited,s,adj);
            } 
        }
        int src=0; //given
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;  //starting initialize with MAX
        }
        dist[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(dist[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            } 
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;  //-1 which is not reachable as given in question
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends