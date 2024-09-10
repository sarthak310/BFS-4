//time: O(n2)
//space: O(n2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat(n * n, -1);
        int r = n - 1, c = 0;
        bool leftToRight = true;
        
        // Flatten the board
        for (int i = 0; i < n * n; i++) {
            if (board[r][c] != -1) 
                flat[i] = board[r][c] - 1;
            else 
                flat[i] = -1;
            
            if (leftToRight) {
                c++;
                if (c == n) {
                    c = n - 1;
                    r--;
                    leftToRight = false;
                }
            } else {
                c--;
                if (c == -1) {
                    c = 0;
                    r--;
                    leftToRight = true;
                }
            }
        }
        
        queue<int> q;
        vector<bool> visited(n * n, false);
        q.push(0); // Start at the first cell
        visited[0] = true;
        int moves = 0;
        
        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            moves++;
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int j = 1; j <= 6; j++) {
                    int next = curr + j;
                    if (next >= n * n) break;
                    
                    if (flat[next] != -1) next = flat[next]; // Move to destination cell if there's a snake or ladder
                    
                    if (next == n * n - 1) return moves; // Reached the last cell
                    
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        return -1; // If we can't reach the last cell
    }
};