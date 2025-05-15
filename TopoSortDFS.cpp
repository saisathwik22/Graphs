// TOPO sort only applied to Directed graph
// Moonfrog Labs, Flipkar, tMorgan Stanley, Accolite, Amazon, Microsof, tOYO Rooms, Samsung, D-E-Shaw, Visa ////
// we are using unordered_map to create adjacency list out of a 2d matrix edges.
// returning a vector ans containing the topo sort order.

// *********************************************** C++ ***************************************************
void DFS(unoredered_map<int, vector<int>> adj, int u, vector<bool>& visited, stack<int>& s) {
  visited[u] = true;
  for(auto &v : adj[u]) {
    if(!visited[v]) {
      DFS(adj, v, visited, s);
    }
  }
  s.push(u);
}
vector<int> topoSortDFS(int V, vector<vector<int>>& edges) {
  vector<bool> visited(V, false);
  stack<int> s;
  unordered_map<int, vector<int>> adj;

  for(vector &ve : edges) {
    int u = ve[0];
    int v = ve[1];
    adj[u].push_back(v);
  }
  for(int i = 0; i < V; i++) {
    if(!visited[i]) {
      DFS(adj, i, visited, s);
    }
  }
  vector<int> ans;
  while(!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}
// ****************************************************** JAVA *****************************************************************
class Solution {
    public static void dfs(Map<Integer, List<Integer>> adj, int u, boolean[] visited, Stack<Integer> s) {
        visited[u] = true;
        for(int v : adj.getOrDefault(u, new ArrayList<>())) {
            if(!visited[v]) {
                dfs(adj, v, visited, s);
            }
        }
        s.push(u);
    }
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        boolean[] visited = new boolean[V];
        Stack<Integer> s = new Stack<>();
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited, s);
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        while(!s.isEmpty()) {
            result.add(s.pop());
        }
        return result;
    }
}
