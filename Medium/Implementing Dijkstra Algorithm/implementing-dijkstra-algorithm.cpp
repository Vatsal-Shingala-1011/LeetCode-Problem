//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//very important line "if record found, then erase it" from set
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        set<pair<int,int>> s;
             // dist, node
        dist[S]=0;
        s.insert(make_pair(0,S));
        while(!s.empty()){
            auto top=*(s.begin());
            int nodeDist=top.first;
            int topNode=top.second;
            s.erase(s.begin());
            //traverse on neighbour
            for(auto neighbour: adj[topNode]){
                if(nodeDist+neighbour[1]<dist[neighbour[0]]){
                    auto record=s.find(make_pair(dist[neighbour[0]],neighbour[0]));
                    //if record found, then erase it
                    if(record != s.end()){
                        s.erase(record);
                    }
                    // update distance
                    dist[neighbour[0]]=nodeDist+neighbour[1];
                    //insert record in set
                    s.insert(make_pair(dist[neighbour[0]],neighbour[0]));
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends