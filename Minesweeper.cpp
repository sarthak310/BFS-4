//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        queue<vector<int>> q;
        q.push({click[0], click[1]});
        board[click[0]][click[1]] = 'B';
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int mines = 0;
            for(int i = 0; i < 8; i++) {
                int r = curr[0] + dirs[i][0];
                int c = curr[1] + dirs[i][1];
                if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'M') {
                    mines++;
                }
            }
            if(mines == 0) {
                for(int i = 0; i < 8; i++) {
                    int r = curr[0] + dirs[i][0];
                    int c = curr[1] + dirs[i][1];
                    if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'E') {
                        q.push({r,c});
                        board[r][c] = 'B';
                    }
                }
            }
            else {
                board[curr[0]][curr[1]] = '0' + mines;
            }        
        }
        return board;
    }
};