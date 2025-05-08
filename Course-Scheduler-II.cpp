// Question same as Course Scheduler I, but here we have to return order of taking courses.
// Order of taking courses, is ntg but TopoSort Order.

// Approach 1 : Using Topo Sort BFS - Kahn's Algo
vector<int> topoSortBFS(unordered_map<int, vector<int>> adj, int n, vector<int>& indegree) {
  queue<int> q;
  int count = 0;
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    if(indegree[i] == 0) {
      count++;
      ans.push_back(i);
      q.push(i);
    }
  }
  while(q.empty()) {
    int u = q.front();
    q.pop();
    for(int &v : adj[u]) {
      indegree[v]--;
      if(indegree[v] == 0) {
        count++;
        ans.push_back(v);
        q.push(v);
      }
    }
  }
  if(count != n) return {};
  return ans;
}
vector<int> findOrder(int numCouses, vector<vector<int>> prerequisites) {
  unordered_map<int, vector<int>> adj;
  vector<int> indegree(numCourses, 0);
  vector<int> ans;
  for(auto &i : prerequisites) {
    int a = i[0];
    int b = i[1];
    adj[b].push_back(a);
    indegree[a]++;
  }
  ans = topoSortBFS(adj, numCourses, indegree);
  return ans;
}

// Approach : DFS
// check for cycle, if found return {}
// if not found return {topoSortOrder};
bool hasCycle = false;
void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& s, vector<bool>& inRecursion) {
  visited[u] = true;
  inRecursion[u] = true;
  for(int &v : adj[u]) {
    if(inRecursion[v] == true) {
      hasCycle = true;
      return;
    }
    if(!visited[v]) {
      DFS(adj, v, visited, s, inRecursion);
    }
  }
  s.push(u);
  inRecursion[u] = false;
}
vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
  unordered_map<int, vector<int>> adj;
  vector<bool> visited(n, false);
  vector<bool> inRecursion(n, false);
  stack<int> s;

  for(auto &i : prerequisites) {
    adj[i[1]].push_back(i[0]);
  }
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      DFS(adj, i, visited, s, inRecursion);
    }
  }
  if(hasCycle == true) {
    return {};
  }
  vector<int> ans;
  while(!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  return ans;
}
