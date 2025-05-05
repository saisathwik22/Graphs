// TOPO sort only applied to Directed graph
// Moonfrog Labs, Flipkar, tMorgan Stanley, Accolite, Amazon, Microsof, tOYO Rooms, Samsung, D-E-Shaw, Visa ////
// we are using unordered_map to create adjacency list out of a 2d matrix edges.
// returning a vector ans containing the topo sort order.

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
