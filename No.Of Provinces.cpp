// Google,Amazon, Microsoft

// we can also create our own graph Map using given adj matrix.
// unordered_map<int, vector<int>> adjList;
// for(int i = 0; i < n; i++) {
//   for(int j = 0; j < n; j++) {
//     if(adj[i][j] == 1) {
//       adjList[i].push_back(j);
//       adjList[j].push_back(i);
//     }
//   }
// }
// OR else we can use the given input adj itself.
// *************************************************** C++ ***************************************************
// DFS :

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

// BFS :

int n;
void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v = 0; v < n; v++) {
      if(adj[u][v] == 1 && !visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}
    
int findCircleNum(vector<vector<int>>& isConnected) {
  n = isConnected.size();
        
  vector<bool> visited(n, false);
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      bfs(isConnected, i, visited);
      count++;
    }
  }
  return count;
}

// ********************************************* JAVA *************************************************
// DFS Approach
class Solution {
    int n;
    public void DFS(int[][] adj, int u, boolean[] visited) {
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && adj[u][v] == 1) {
                DFS(adj, v, visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        n = isConnected.length;
        boolean[] visited = new boolean[n];
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                DFS(isConnected, i, visited);
            }
        }
        return count;
    }
}
// BFS Approach
class Solution {
    int n;
    public void bfs(int[][] adj, int u, boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        visited[u] = true;
        while(!q.isEmpty()) {
            int curr = q.poll();
            for(int v = 0; v < n; v++) {
                if(adj[curr][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.add(v);
                }
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        n = isConnected.length;
        boolean[] visited = new boolean[n];
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
}

 
