// leetcode 994
// Tiktok, Microsoft, Amazon,Adobe, google
// Multi Source BFS

// TC = O(m*m) SC = O(m*n)

class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        int freshOrange = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.offer(new int[]{i, j});
                } else if(grid[i][j] == 1) {
                    freshOrange += 1;
                }
            }
        }
        if(freshOrange == 0) return 0;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        while(!q.isEmpty()) {
            int size = q.size();
            while(size-- > 0) {
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                for(int[] dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1) {
                        grid[x_][y_] = 2;
                        q.offer(new int[]{x_, y_});
                        freshOrange -= 1;
                    }
                }
            }
            time += 1;
        }
        if(freshOrange == 0) {
            return time - 1;
        }
        return -1;
    }
}
