#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:



    int arahbaris[4] = {-1, 1, 0, 0};
    int arahkolom[4] = {0, 0, -1, 1};

    
    struct titik{
        int x,y;
    };

    queue<titik> antrian;
    bool is_valid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int total_fresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    antrian.push({i,j});
                    
                } else {
                    if (grid[i][j] == 1){
                        total_fresh++;
                    }
                }
            }
        }

        int minute = 0;
        while(!antrian.empty()){
            int size = antrian.size();
            bool berubah = false;

            for (int s = 0; s < size; s++) {
                titik cur = antrian.front();
                antrian.pop();

                int x = cur.x;
                int y = cur.y;

                for (int i = 0; i < 4; i++) {
                    int nx = x + arahbaris[i];
                    int ny = y + arahkolom[i];

                    if (is_valid(grid, nx, ny) && grid[nx][ny] == 1){
                        berubah = true;
                        grid[nx][ny] = 2;
                        total_fresh--;
                        antrian.push({nx, ny});
                     }
                }
            }

            if (berubah) minute++;
        }
        if (total_fresh != 0) return -1;
        return minute;
    }

};



int main(){
    vector<vector<int>> p = {{1,1,0},{0,1,1},{0,1,2}};
    Solution z;
    int solv = z.orangesRotting(p);
    cout << solv << endl;
    
}
