// User function Template for Java

class Solution {
    public int[] bellmanFord(int V, int[][] edges, int src) {
        // code here
        int m = edges.length;
        int n = edges[0].length;
        int[] result = new int[V];
        int INF = 100000000;
        
        Arrays.fill(result, INF);
        result[src] = 0;
        
        for(int count = 1; count <= V - 1; count++){
            for(int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(result[u] != INF && result[u] + wt < result[v]) {
                    result[v] = result[u] + wt;
                }
            }
        }
        // now detect negative cycles
        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(result[u] != INF && result[u] + wt < result[v]) {
                return new int[]{-1};
            }
        }
        return result;
    }
}
