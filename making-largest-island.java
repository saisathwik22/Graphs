// leetcode 827 - Google, Uber

// Brute Force - TLE
// TC : O(n*n*n*n) SC : O(n*n)
class Solution {
    int[][] directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int n;
    int DFS(int[][] grid, int i, int j, boolean[][] visited) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j] == true) {
            return 0;
        }

        visited[i][j] = true;
        int count = 1;

        for(int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            count = count + DFS(grid, i_, j_, visited);
        }
        return count;
    }

    public int largestIsland(int[][] grid) {
        n = grid.length; // row = col = n

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1; // convert this 0 to 1 and now search for large island

                    boolean[][] visited = new boolean[n][n];
                    int largestIslandSize = 0;
                    for(int x = 0; x < n; x++) {
                        for(int y = 0; y < n; y++) {
                            if(grid[x][y] == 1 && visited[x][y] == false) {
                                largestIslandSize = Math.max(largestIslandSize, DFS(grid, x, y, visited));
                            }
                        }
                    }
                    
                    maxArea = Math.max(maxArea, largestIslandSize);
                    grid[i][j] = 0; // undo
                }
            }
        }

        if(maxArea == 0) { // this implies, maxArea was not updated because there were no 0s in the grid, all are 1s
            return n*n;
        }
        else {
            return maxArea;
        }
    }
}

// Better Solution
class Solution {
    int[][] directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int n;
    int DFS(int[][] grid, int i, int j, boolean[][] visited) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j] == true) {
            return 0;
        }

        visited[i][j] = true;
        int count = 1;

        for(int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            count = count + DFS(grid, i_, j_, visited);
        }
        return count;
    }

    public int largestIsland(int[][] grid) {
        n = grid.length; // row = col = n

        boolean[][] visited = new boolean[n][n];

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    maxArea = Math.max(maxArea, DFS(grid, i, j, visited));
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1; // convert this 0 to 1 and now search for large island
                    
                    visited = new boolean[n][n];
                    int size = DFS(grid, i, j, visited);
                    maxArea = Math.max(maxArea, size);
                    grid[i][j] = 0; // undo
                }
            }
        }

        if(maxArea == 0) { // this implies, maxArea was not updated because there were no 0s in the grid, all are 1s
            return n*n;
        }
        else {
            return maxArea;
        }
    }
}

// Optimal Solution - Accepted
// TC : O(m*n) SC : O(m*n)

class Solution {
    public int m, n;
    public final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    private int DFS(int[][] grid, int i, int j, int uniqueID) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = uniqueID;
        int count = 1;
        for(int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            count += DFS(grid, i_, j_, uniqueID);
        }
        return count;
    }
    public int largestIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int maxArea = 0;
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int islandID = 2;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int size = DFS(grid, i, j, islandID);
                    maxArea = Math.max(maxArea, size);
                    islandSizes.put(islandID, size);
                    islandID += 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    Set<Integer> uniqueIslands = new HashSet<>();
                    for(int[] dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0) {
                            uniqueIslands.add(grid[x][y]);
                        }
                    }
                    int sum = 1; //convert 0 to 1
                    for(int id : uniqueIslands) {
                        sum += islandSizes.get(id);
                    }
                    maxArea = Math.max(maxArea, sum);
                }
            }
        }
        return maxArea;
    }
}
