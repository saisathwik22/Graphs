// DSu Approach
//2316
class Solution {
    int[] parent;
    int[] rank;
    public int find(int x) {
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
    public long countPairs(int n, int[][] edges) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        // int remaining = n;
        for(int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];
            Union(u, v);
        }
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++) {
            int parent = find(i);
            map.put(parent, map.getOrDefault(parent, 0) + 1); // map[aorent]++ in c++
        }
        long result = 0;
        long remaining = n;
        for(Map.Entry<Integer, Integer> it : map.entrySet()) {
            long size = it.getValue(); // access .second() in c++
            result = result + (size) * (remaining - size);
            remaining = remaining - size;
        }
        return result;
    }
}
