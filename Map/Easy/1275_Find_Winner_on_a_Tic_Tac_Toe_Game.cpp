class Solution {
public://0(n) is tc and 0(1) is sc
    string tictactoe(vector<vector<int>>& moves){
       vector<int>row(3,0);
       vector<int>col(3,0);
       int dg = 0,anti = 0;
       int turn  = 1;
       for(auto move : moves){
          int r = move[0], c= move[1];
          row[r] += turn;
          col[c] += turn;
          if(r == c) dg += turn;  // diagonal
          if(r+c == 2) anti += turn;   // anti diagonal
          if(abs(row[r]) == 3 || abs(col[c]) == 3 || abs(dg) == 3 || abs(anti) == 3){
            return turn == 1 ? "A" : "B";
          } 
          turn *= -1 ;  // next turn for B.
       } 
       return moves.size() == 9 ? "Draw" : "Pending";
    }
};
