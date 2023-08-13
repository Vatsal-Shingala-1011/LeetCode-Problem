class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) {
            // Node is currently being visited (part of the current traversal) - cycle detected
            return false;
        }
        if (visited[node] == 2) {
            // Node has been fully visited in a previous traversal, no need to revisit
            return true;
        }
        
        visited[node] = 1; // Mark as currently being visited
        
        for (int nbr : adj[node]) {
            if (!dfs(nbr, adj, visited)) {
                return false; // Cycle detected in the subtree
            }
        }
        
        visited[node] = 2; // Mark as fully visited
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) {
                    return false; // Cycle detected
                }
            }
        }
        
        return true; // No cycle detected
    }
};
