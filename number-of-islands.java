// Paytm, Amazon, Microsoft, Samsung, Snapdeal, Citrix, DE Shaw, Ola cabs, Visa, Linkedin, Opera, Streamoid Technologies, 

// DFS 
// TC : O(m*n)

class Solution {
    public void DFS(char[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // boolean[][] visited = new boolean[m + 1][n + 1];

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
}


// BFS
// TC : O(m*n) SC : O(m*n)
class Solution {
    int m, n;
    private int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    private boolean isSafe(char[][] grid, int i, int j) {
        return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == '1';
    }
    public void BFS(char[][] grid, int i, int j, Queue<int[]> q) {
        q.offer(new int[]{i, j});
        grid[i][j] = '$';

        while(!q.isEmpty()) {
            int[] curr = q.poll();

            for(int[] dir : directions) {
                int i_ = curr[0] + dir[0];
                int j_ = curr[1] + dir[1];

                if(isSafe(grid, i_, j_)) {
                    q.offer(new int[]{i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }
    public int numIslands(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int count = 0;
        Queue<int[]> q = new ArrayDeque<>();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    BFS(grid, i, j, q);
                    count++;
                }
            }
        }
        return count;
    }
}
