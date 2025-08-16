// leetcode 417 - amazon, microsoft, facebook, google, uber, salesforce, apple, yahoo, bytedance, bloomberg

class Solution {
    int m, n;
    int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    public void dfs(int row, int col, boolean[][] visited, int[][] heights) {
        if(visited[row][col] == true) return;

        visited[row][col] = true;

        for(int[] dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) {
                continue;
            }
            if(heights[new_row][new_col] < heights[row][col]) {
                continue;
            }
            dfs(new_row, new_col, visited, heights);
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if(heights == null || heights.length == 0) {
            return result;
        }
        m = heights.length;
        n = heights[0].length;

        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];

        // DFS from 1st row (pacific flood) and last row (atlantic flood)
        for(int col = 0; col < n; col++){
            dfs(0, col, pacific, heights);
            dfs(m-1, col, atlantic, heights);
        }
        // DFS from 1st col (pacific flood) and last col (atlantic flood)
        for(int row = 0; row < m; row++) {
            dfs(row, 0, pacific, heights);
            dfs(row, n-1, atlantic, heights);
        }
        // collect intersection of pacific and atlantic reachability and add to result
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;

    }
}
