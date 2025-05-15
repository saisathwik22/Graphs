// Question same as Course Scheduler I, but here we have to return order of taking courses.
// Order of taking courses, is ntg but TopoSort Order.
// ****************************************** C++ **********************************************************
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
// ********************************************************* JAVA ***************************************************
// Approach - BFS (kahns Algo) 
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[numCourses];
        for(int[] pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            adj.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
            indegree[a]++;
        }
        Queue<Integer> q = new LinkedList<>();
        List<Integer> result = new ArrayList<>();

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.offer(i);
                result.add(i);
            }
        }
        while(!q.isEmpty()) {
            int u = q.poll();
            for(int v : adj.getOrDefault(u, new ArrayList<>())) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.offer(v);
                    result.add(v);
                }
            }
        }
        if(result.size() != numCourses) return new int[0];
        int[] order = new int[numCourses];
        for(int i = 0; i < numCourses; i++) {
            order[i] = result.get(i);
        }
        return order;
    }
}

// Approach DFS
class Solution {
    boolean hasCycle;
    public void dfs(Map<Integer, List<Integer>> adj, int u, boolean[] visited, boolean[] inRecursion, Stack<Integer> s) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int v : adj.getOrDefault(u, new ArrayList<>()))  {
            if(inRecursion[v]) {
                hasCycle = true;
                return;
            }
            if(!visited[v]) {
                dfs(adj, v, visited, inRecursion, s);
                if(hasCycle) return;
            }
        }
        inRecursion[u] = false;
        s.push(u);
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int[] pre : prerequisites) {
            adj.computeIfAbsent(pre[1], k -> new ArrayList<>()).add(pre[0]);
        }

        boolean[] visited = new boolean[numCourses];
        boolean[] inRecursion = new boolean[numCourses];
        Stack<Integer> s = new Stack<>();
        hasCycle = false;

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited, inRecursion, s);
                if(hasCycle) return new int[0];
            }
        }
        int[] result = new int[numCourses];
        for(int i = 0; i < numCourses; i++) {
            result[i] = s.pop();
        }
        return result;
    }
}
