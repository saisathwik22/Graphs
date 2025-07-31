// Microsoft, Google, 1765 leetcode
// TC : O(m*n) SC : O(m*n)

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length;
        int n = isWater[0].length;
        int[][] height = new int[m][n];

        Queue<int[]> q = new LinkedList<>();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    q.offer(new int[]{i, j});
                    height[i][j] = 0;
                } else {
                    height[i][j] = -1;
                }
            }
        }

        // MultiSource BFS
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.isEmpty()) {
            int N = q.size();
            while(N-- > 0) {
                int[] curr = q.poll();
                int i = curr[0];
                int j = curr[1];

                for(int[] dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        q.offer(new int[]{i_, j_});
                    }
                }
            }
        }
        return height;

    }
}
