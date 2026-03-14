#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<bool> p;
    bool visited[7] = {false};

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;

        dfs(nums,cur);
        return result;

    }
    void dfs(vector<int> input,vector<int> &cur){
        if(cur.size() == input.size()){
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < input.size(); i++){
           if (!visited[i]) {
                cur.push_back(input[i]);
                visited[i] = true;
                dfs(input, cur);
                cur.pop_back();
                visited[i] = false;
           }
           
        }
    }
};

int main(){
    Solution s2;
    vector<int> s ={1,2,3};
    vector<vector<int>> p = s2.permute(s);
    for(int i = 0; i < p.size(); i++){
        for(int j = 0; j < p[i].size(); j++){
            cout << p[i][j];
        }
        cout << endl;
    }

}

