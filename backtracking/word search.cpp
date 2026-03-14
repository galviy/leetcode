#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool visited[100][100] = {false};

    bool found = false;
    void menjelajah(int x, int y,vector<vector<char>>& board,int index, string word){

        if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size()){
            if (!visited[x][y]){
                visited[x][y] = true;
                if (board[x][y] != word[index]) return;
                if(index == word.length() -1 ){
                    cout << "wow dapet" << endl;
                    found = true;
                    return;
                 }
                
                    menjelajah(x+1, y, board, index+1, word);
                    menjelajah(x-1, y, board, index+1, word);
                    menjelajah(x, y+1, board, index+1, word);
                    menjelajah(x, y-1, board, index+1, word);
                    visited[x][y] = false;

            }
        }
        else {
            return;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if (!visited[i][j]){
                    
                    if (board[i][j] == word[0]){

                        menjelajah(i,j,board,0,word);
                    }
                }
            }
        }
        return found;
    }
};


int main(){
    vector<vector<char>> board  = {
         {'A','B','C','D'},
         {'S','A','A','T'},
         {'A','C','A','E'}
    };
    Solution s;
    bool p = s.exist(board, "CAT");
    if (p) cout <<"ketemu";
    else cout << "gk ketemu"<< endl;
}