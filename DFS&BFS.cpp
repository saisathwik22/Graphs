// ******************************************* C++ *****************************************************
// result array return respective DFS and BFS traversal orders.
void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result) {
  if(visited[u] == true) return;
  visited[u] = true;
  result.push_back(u);
  for(int &v : adj[u]) {
    if(visited[i] == false) {
      DFS(adj, v, visited, result);
    }
  }
}

// adjList can also be declared with unordered_map<int, vector<int>> adjList;

void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result) {
  queue<int> q;
  q.push(u);
  visited[u] = true;
  result.push_back(u);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int &v : adj[u]) {
      if(!visited[v]) {
        q.push(v);
        visited[v] = true;
        result.push_back(v);
      }
    }
  }
}
// ****************************************************** JAVA *********************************************************
// DFS
public static void DFS(List<List<Integer>> adj, int u, boolean[] visited, List<Integer> result) {
  if(visited[u]) return;
  visited[u] = true;
  result.add(u);
  for(int v : adj.get(u)) {
    if(!visited[v]) {
      DFS(adj, v, visited, result);
    }
  }
}
// BFS
public static void BFS(List<List<Integer>> adj, int u, boolean[] visited, List<Integer> result) {
  Queue<Integer> q = new LinkedList<>();
  q.add(u);
  visited[u] = true;
  result.add(u);
  while(!q.isEmpty()) {
    int curr = q.poll();
    for(int v : adj.get(curr)) {
      if(!visited[v]) {
        q.add(v);
        visited[v] = true;
        result.add(v);
      }
    }
  }
}
