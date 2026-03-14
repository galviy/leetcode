#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int visited[101][101] = {false};
    bool is_island = false;
    int counter = 0;

    bool isValid(vector<vector<char>> grid ,int x , int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }

    void dfs(vector<vector<char>> grid,int x , int y){
        if (!isValid(grid,x,y)) return;
        if (visited[x][y]) return;
        
        visited[x][y] = true;
        if (grid[x][y] == '0') return;
        cout << x << " " << y << endl;
    
        dfs(grid,x+1, y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){


                if (grid[i][j] == '1' && !visited[i][j]){
                    counter++;
                    dfs(grid,i,j);
                }
            }
        }
       
        cout << counter << endl;
        return counter;
    }
};


int main(){
    vector<vector<char>> grid = {
    {'0','1','1','0','1'},
    {'1','0','1','0','1'},
    {'0','1','1','0','1'},
    {'0','1','0','0','1'}
};
    Solution s;
    int z = s.numIslands(grid);

}