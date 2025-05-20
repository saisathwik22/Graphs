// leetcode 1319
// AMAZON
// n nodes given, edges given.
// find min num of edges to make all the nodes connected.
// 

// DSU approach
// find no of components, ans = components - 1;
// to connect x components, we need (x - 1) edges
// for n nodes we need atleast (n - 1) edges to connect all nodes.
// ************************************** JAVA ********************************************
class Solution {
    int[] parent;
    int[] rank;
    public int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    public void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    public int makeConnected(int n, int[][] connections) {
        if(connections.length < n - 1) {
            return -1;
        }
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        int components = n;
        for(int[] v : connections) {
            if(find(v[0]) != find(v[1])) {
                Union(v[0], v[1]);
                components--;
            }
        }
        return components - 1;
    }
}
// ************************************************ C++ *******************************************
class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int components = n;
        for(auto &vec : connections) {
            if(find(vec[0]) != find(vec[1])) {
                Union(vec[0], vec[1]);
                components--;
            }
        }
        return components - 1;
    }
};
