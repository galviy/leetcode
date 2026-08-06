#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {

public:
    struct koordinat{
        int x;
        int y;
    };
    

    int isValid(const vector<vector<char>> &board, int x, int y) {
        return (x >= 0 && x < board.size()) && (y >= 0 && y < board[x].size());
    }
    void bfs(vector<vector<char>> &board,int i, int j){
        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        queue<koordinat> q;

     
        q.push({i,j});

        while(!q.empty()){
            koordinat node = q.front();
            q.pop();

            for(int t = 0; t < 4; t++){
                int roww = node.x + row[t];
                int coll = node.y + col[t];
                if(isValid(board,roww,coll) &&  board[roww][coll] == 'O'){
                   // printf("Menelusuri (%d,%d)\n",roww,coll);
                   board[roww][coll] = 't';
                    q.push({roww,coll});
                }
            }
        }

    }
    void solve(vector<vector<char>> &board){
        if (board.empty()) return;
 
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O') bfs(board,0,i);
            if(board[board.size()-1][i] == 'O') bfs(board,board.size()-1,i);
        }
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O') bfs(board,i,0);
            if(board[i][board[0].size()-1] == 'O') bfs(board,i,board.size()-1);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                
                } else {
                    if(board[i][j] == 't'){
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }
};

int main(){
    vector<vector<char>> p = {{'X', 'X', 'X', 'X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution sol;
    sol.solve(p);

}