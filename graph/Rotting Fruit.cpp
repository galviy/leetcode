#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:

    bool visited[11][11];
    
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 2){

                }
            }
        }
    }
    void dfs(vector<vector<int>> &grid,int x, int y){
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size()){

        }
    }
};



int main(){
    vector<vector<int>> p = {{1,1,0},{0,1,1},{0,1,2}};

}