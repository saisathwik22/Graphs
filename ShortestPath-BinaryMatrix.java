// find shortest path from (0,0) to (n-1, n-1) in binary matrix.
// find length of shortest path
// length of shortest path == no. of visited cells in that path.
// leetcode 1091 -- Google, Meta, Amazon, Microsoft

// JAVA code
// Dijkstra algo
class Solution {
    int[][] directions = {
        {1, 1}, {0, 1}, {1, 0}, {-1, 0},
        {0, -1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    public boolean isSafe(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if(m == 0 || n == 0 || grid[0][0] != 0) { return -1; }

        int[][] result = new int[m][n];
        for(int i = 0; i < m; i++) {
            Arrays.fill(result[i], Integer.MAX_VALUE);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.offer(new int[]{0, 0, 0});
        result[0][0] = 0;
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0];
            int x = curr[1];
            int y = curr[2];

            for(int[] dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                
                int dist = 1;
                if(isSafe(x_, y_, n) && grid[x_][y_] == 0 && d + dist < result[x_][y_]) {
                    pq.offer(new int[]{d + dist, x_, y_});
                    result[x_][y_] = d + dist;
                    grid[x_][y_] = 1;
                }
            }
        }
        if(result[m - 1][n - 1] == Integer.MAX_VALUE) return -1;
        return result[m - 1][n - 1] + 1;
    }
}
// BFS Approach; -- works only because edges are of wt = 1
class Solution {
    int[][] directions = {
        {1, 1}, {0, 1}, {1, 0}, {-1, 0},
        {0, -1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    public boolean isSafe(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length; // .size()
        int n = grid[0].length;
        if(m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }
        
        Queue<int[]> q = new LinkedList<>(); // queue<pair<int, int>> q
        q.offer(new int[]{0, 0}); // q.push({0, 0})
        grid[0][0] = 1;

        int level = 0;

        while(!q.isEmpty()) { // .empty()
            int N = q.size();
            while(N > 0) {
                int[] pair = q.poll(); // .front() && .pop()
                int x = pair[0]; // .first
                int y = pair[1]; // .second
                if(x == m-1 && y == n-1) {
                    return level + 1;
                }
                for(int[] dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_, n) && grid[x_][y_] == 0) {
                        q.offer(new int[]{x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
                N--;
            }
            level += 1;
        }
        return -1;
    }
}
