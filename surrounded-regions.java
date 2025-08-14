// leetcode 130

class Solution {
    public int[] delRow = {-1, 0, 1, 0};
    public int[] delCol = {0, 1, 0, -1};
    public void DFS(int row, int col, int[][] visited, char[][] board) {
        visited[row][col] = 1;

        int m = board.length;
        int n = board[0].length;

        // check for top, right, bottom, left
        // top = row-1, col
        // right = row, col+1
        // bottom = row+1, col
        // left = row, col-1

        for(int i = 0; i < 4; i++) {
            int new_row = row + delRow[i];
            int new_col = col + delCol[i];
            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && visited[new_row][new_col] == 0 && board[new_row][new_col] == 'O') {
                DFS(new_row, new_col, visited, board);
            }
        }


    }
    public void solve(char[][] board) {
        
        int m = board.length;
        int n = board[0].length;
        int[][] visited = new int[m][n];
        for(int i = 0; i < m; i++) {
            Arrays.fill(visited[i], 0);
        }
        for(int j = 0; j < n; j++) {
            // 1st row
            if(visited[0][j] == 0 && board[0][j] == 'O') {
                DFS(0, j, visited, board);
            }
            // last row
            if(visited[m-1][j] == 0 && board[m-1][j] == 'O') {
                DFS(m-1, j, visited, board);
            }
        }
        for(int i = 0; i < m; i++) {
            // 1st column
            if(visited[i][0] == 0 && board[i][0] == 'O') {
                DFS(i, 0, visited, board);
            }
            // last column
            if(visited[i][n-1] == 0 && board[i][n-1] == 'O') {
                DFS(i, n-1, visited, board);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
