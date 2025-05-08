// Amazon, Microsoft, Accolite, Meta, Flipkart, Twitter, Moonfrog Labs, OYO Rooms....
// [a, b] - you must do task b first to do task a; b ----> a;
// if graph contains cycles, output == false;
// topological sort only possible for Directed Acyclic graphs,
// if topological sort returns true, output true, else false;
// because for all the courses to be completed, graph shouldn't contain any cycles....

// BFS Approach - using BFS cycle check - Kahn's Algo (TOPO SORT)
bool topoSortCheck(unordered_map<int, vector<in>>& adj, int n, vector<int>& indegree) {
  queue<int> q;
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(indegree[i] == 0) {
      count++;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int &v : adj[u]) {
      indegree[v]--;
      if(indegree[v] == 0) {
        count++;
        q.push(v);
      }
    }
  }
  if(count == n) return true; // all nodes visited, cycle not found.
  return false; //cycle found
}
bool isCompleted(int N, vector<vector<int>> prereq) {
  unordered_map<int, vector<int>> adj;
  vector<int> indegree(N, 0);
  for(auto &i : prereq) {
    int a = i[0];
    int b = i[1];
    adj[b].push_back(a);
    indegree[a]++;
  }
  return topoSortCheck(adj, N, indegree);
}

// using DFS cycle Detection algo
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            }
            else if(inRecursion[v] == true) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &i : prerequisites) {
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)) {
                return false;
            }
        }
        return true;
    }
