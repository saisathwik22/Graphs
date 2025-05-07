// Google,Amazon, Microsoft

int n;
void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
  visited[u] = true;
  for(int v = 0; v < n; v++) {
    if(!visited[v] && adj[u][v] == 1) {
      DFS(adj, v, visited);
    }
  }
}
int numOfProvinces(vector<vector<int>> adj, int V) {
  n = V;
  vector<bool> visited(n, false);
  int count = 0;
  for(int i = 0; i < V; i++) {
    if(!visited[i]) {
      count++;
      DFS(adj, i, visited);
    }
  }
  return count;
}
