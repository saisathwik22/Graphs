// DFS

class Solution {
    public int DFS(int[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;
        int area = 1;

        area += DFS(grid, i + 1, j);
        area += DFS(grid, i - 1, j);
        area += DFS(grid, i, j + 1);
        area += DFS(grid, i, j - 1);

        return area;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // boolean[][] visited = new boolean[m + 1][n + 1];

        int count = 0;
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                    int area = DFS(grid, i, j);
                    ans = Math.max(ans, area);
                }
            }
        }

        return ans;
    }
}


// BFS
class Solution {
    private int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    private boolean isSafe(int[][] grid, int i, int j) {
        return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1;
    }
    private int BFS(int[][] grid, int i, int j, Queue<int[]> q) {
        q.offer(new int[]{i, j});
        grid[i][j] = 0;
        int area = 1;
        while(!q.isEmpty()) {
            int[] curr = q.poll();
            for(int[] dir : directions) {
                int i_ = curr[0] + dir[0];
                int j_ = curr[1] + dir[1];
                if(isSafe(grid, i_, j_)) {
                    q.offer(new int[]{i_, j_});
                    grid[i_][j_] = 0;
                    area += 1;
                }
            }
        }
        return area;
    }
    public int maxAreaOfIsland(int[][] grid) {
        if(grid.length == 0) return 0;
        int ans = 0;
        Queue<int[]> q = new ArrayDeque<>();
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 1) {
                    
                    ans = Math.max(ans, BFS(grid, i, j, q));
                }
            }
        }
        return ans;
    }
}
