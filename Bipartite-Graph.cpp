// Check if graph (UDG) is biaprtite or not
// A graph is bipartite if:
// you are able to color nodes of graph with 2 colors such that no two adjacent nodes have same color.

// DFS Approach:
bool isBipartiteDFS(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& color, int currNodeColor) {
  color[currNode] = currNodeColor;
  for(int &v : adj[currNode]) {
    if(color[v] == color[currNode]) {
      return false;
    }
    if(color[v] == -1) {
      int colorV = 1 - currNodeColor;
      if(isBipartiteDFS(adj, v, color, colorV) == false) {
        return false;
      }
    }
  }
  return true;
}
bool isBipartite(int V, vector<vector<int>> edges) {
  unordered_map<int, vector<int>> adj;
  for(int &v : edges) {
    int u = i[0];
    int v = i[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> color(V, -1);
  for(int i = 0; i < V; i++) {
    if(color[v] == -1) {
      if(isBipartiteDFS(adj, i, color, 1) == false) {
        return false;
      }
    }
  }
  return true;
}

// BFS Approach
bool isiBipartiteBFS(vector<vector<int>>& adj, int currNode, vector<int>& color, int currNodeColor) {
  queue<int> q;
  q.push(currNode);
  color[currNode] = currNodeColor;
  while(!q.empty()) {
    int U = q.front();
    q.pop();
    for(int &v : adj[U]) {
      if(color[v] == color[U]) {
        return false;
      }
      else if(color[v] == -1) {
        color[v] = 1 - color[U];
        q.push(v);
      }
    }
  }
  return true;
}


bool isBipartite(int V, vector<vector<int>> edges) {
  unordered_map<int, vector<int>> adj;
  for(int &v : edges) {
    int u = i[0];
    int v = i[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> color(V, -1);
  for(int i = 0; i < V; i++) {
    if(color[v] == -1) {
      if(isBipartiteBFS(adj, i, color, 1) == false) {
        return false;
      }
    }
  }
  return true;
}
