// Amazon, Microsoft, VISA

class Solution {
    
    public void dfsFill(int u, ArrayList<ArrayList<Integer>> adj, boolean[] visited, Stack<Integer> st) {
        visited[u] = true;
        for(int v : adj.get(u)) {
            if(!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }
    public void dfsTraversal(int u, ArrayList<ArrayList<Integer>> adjReversed, boolean[] visited) {
        visited[u] = true;
        
        for(int v : adjReversed.get(u)) {
            if(!visited[v]) {
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }
    
    // Function to find number of strongly connected components in the graph.
    public int kosaraju(ArrayList<ArrayList<Integer>> adj) {
        int V = adj.size();
        // step 1 - store Topo sort order of dfs in stack
        Stack<Integer> st = new Stack<>();
        
        boolean[] visited = new boolean[V];
        Arrays.fill(visited, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        //step-2 make a reversal graph
        ArrayList<ArrayList<Integer>> adjReversed = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adjReversed.add(new ArrayList<>());
        }
        
        for(int u = 0; u < V; u++) {
            for(int v : adj.get(u)) {
                adjReversed.get(v).add(u);
            }
        }
        
        int countSCC = 0;
        Arrays.fill(visited, false);
        
        while(!st.isEmpty()) {
            int node = st.peek();
            st.pop();
            if(!visited[node]) {
                dfsTraversal(node, adjReversed, visited);
                countSCC++;
            }
            
        }
        return countSCC;
    }
}
