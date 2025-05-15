// MICROSOFT, AMAZON, GOOGLE
// cycle detect using DSU
// iterate through graph nodes... process all the edges
// processing an edge means, pick an edge and check parents of two nodes
// if parents of two nodes are not equal , then apply union to them;
// if parents of two nodes are found equal, then CYCLE exists
// if you donot find any edge from graph such that the parents of those two nodes are equal --> cycle donot exist;

vector<int> parent;
vector<int> rank;
int find(int x) {
  if(parent[x] == x) {
    return x;
  }
  return parent[x] = find(parent[x]);
}
void unionByRank(int x, int y) {
  int x_parent = find(x);
  int y_parent = find(y);
  if(rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if(rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  }
  else if(rank[x_parent] == rank[y_parent]) {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}
int detectCycle(int X, vector<vector<int>> adj) {
  parent.resize(V);
  rank.resize(V, 0);

  for(int i = 0; i < V; i++) {
    parent[i] = i;
  }

  for(int u = 0; u < V; u++) {
    for(int &v : adj[u]) {
      if(u < v) {
        if(find(u) == find(v)) return true;
        else unionByRank(u, v);
      }
    }
  }
  return false;
}
