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
