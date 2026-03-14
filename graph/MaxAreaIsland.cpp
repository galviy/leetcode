#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int visited[101][101] = {false};
    bool is_island = false;
    int counter = 0;



    bool isValid(vector<vector<int>> grid ,int x , int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }

    void dfs(vector<vector<int>> grid,int x , int y, int &pp){
        if (!isValid(grid,x,y)) return;
        if (visited[x][y]) return;
        
        visited[x][y] = true;
        if (grid[x][y] == 0) return;
        pp = pp+1;
         //cout << "banyak pp " << pp << " " << x << " " << y << endl;
        dfs(grid,x+1, y, pp);
        dfs(grid,x-1,y, pp);
        dfs(grid,x,y+1, pp);
        dfs(grid,x,y-1, pp);
       
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxx = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){

                int konterwkwk = 0;

                if (grid[i][j] == 1 && !visited[i][j]){
                    counter++;
                    dfs(grid,i,j, konterwkwk);
                    cout << "total " << konterwkwk << endl;
                    maxx = max(konterwkwk,maxx);
                }
            }
        }
       
        cout << counter << endl;
        return maxx;
    }
};


int main(){
   vector<vector<int>> grid = {
        {0,1,1,0,1},
        {1,0,1,0,1},
        {0,1,1,0,1},
        {0,1,0,0,1}
    };
    Solution s;
    int z = s.maxAreaOfIsland(grid);

}