/*
General idea

crush: in two directions (horizontally and vertically): go through each row/col, 
and mark any longer-than-3 runs negative (can't mark 0 for now, other row/cols might 
need the value of this). Use a little Math.abs's help in this process to distinguish 
a negative candy's negative sign and its value. Return a boolean value to indicate 
whether we should go on or terminate.
drop: this is exactly what you were asked to do in problem LeecCode 283.
*/

class Solution {
    bool crush (vector<vector<int>>& board) {
        bool res = false;
        // Mark negative flag to all to-be-crushed candies in 2 directions
        // horizontally & vertically
        for (int i = 0; i < board.size(); i++) {
            int anchor = 0, val = board[i][0];
            int j = 0;
            for (; j < board[0].size(); j++) {
                if (board[i][j] != val && board[i][j] != -val) {
                    if (val != 0 && j - anchor >= 3) {
                        res = true;
                        for (int k = anchor; k < j; k++)
                            board[i][j] = -abs(board[i][j]);
                    }
                    anchor = j;
                    val = board[i][anchor];
                }
            }
            if (val != 0 && j - anchor >= 3) {
                res = true;
                for (int k = anchor; k < j; k++)
                    board[i][j] = -abs(board[i][j]);
            }
        }

        for (int j = 0; j < board[0].size9(); j++) {
            int anchor = 0, val = board[0][j];
        } 
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        
    }
};