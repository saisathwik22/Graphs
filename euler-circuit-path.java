// Google
// TC : O(v + e)
// DFS

class Solution {
    
    public void DFS(List<Integer>[] adj, int u, boolean[] visited) {
        visited[u] = true;
        
        for(int v : adj[u]) {
            if(!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }
    
    public boolean isConnected(int V, List<Integer>[] adj) {
        
        int nonZeroDegreeNode = -1;
        for(int i = 0; i < V; i++) {
            if(adj[i].size() != 0) {
                nonZeroDegreeNode = i;
                break;
            }
        }
        
        boolean[] visited = new boolean[V];
        // starts DFS from nonZeroDegreeNode
        DFS(adj, nonZeroDegreeNode, visited);
        
        // check if all non-zero degree nodes are visited
        for(int i = 0; i < V; i++) {
            if(visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }
        
        return true;
    }
    public int isEulerCircuit(int V, List<Integer>[] adj) {
        // code here
        
        // Check if all non-zero degree nodes are connected
        if(isConnected(V, adj) == false) {
            return 0;
        }
        
        // Count odd degree nodes
        int oddDegreeCount = 0;
        for(int i = 0; i < V; i++) {
            if(adj[i].size() % 2 != 0) {
                oddDegreeCount++;
            }
        }
        if(oddDegreeCount > 2) {
            return 0; //non euler graph
        }
        if(oddDegreeCount == 2) {
            return 1; // only euler path, no circuit
        }
        return 2;
        
    }
}
