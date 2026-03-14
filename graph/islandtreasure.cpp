#include <iostream>
#include <vector>

#include <cstring>

using namespace std;

#define INF 2147483647



class Solution {
public:
    bool visited[101][101] = {false};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                
                if (grid[i][j] == INF){
                    cout << "titik awal " << i << " " << j << endl;
                 
                    dfs(grid,i,j,0,i,j);
                 
                    memset(visited,false,sizeof(visited));
                    
                }
            }
        }
    }
    

    void dfs(vector<vector<int>>& grid, int x, int y,int count, int x_src, int y_src){
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size()){
            if (visited[x][y]) 
                return;
           
            visited[x][y] = true;
           

           if(grid[x][y] == -1)
                return;
            if(count >= grid[x_src][y_src])
                return;
            if(grid[x][y] == 0){

                cout << " ketemu 0 di " << count << " " << x << " " << y << " source di " << x_src << " " << y_src << endl;
                grid[x_src][y_src] = min(count, grid[x_src][y_src]);
                return;
            }
       
            dfs(grid,x+1,y,count+1,x_src,y_src);
            dfs(grid,x-1,y,count+1,x_src,y_src);
            dfs(grid,x,y+1,count+1,x_src,y_src);
            dfs(grid,x,y-1,count+1,x_src,y_src);
            visited[x][y] = false;
        }
    }
};



int main(){
    vector<vector<int>> grid = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };
    Solution p;
     p.islandsAndTreasure(grid);
     for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
     }
    
}