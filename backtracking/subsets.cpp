#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp_subset;
        dfs(nums, temp_subset, answer,0);
        return answer;
    }
    void dfs(vector<int> input,vector<int>& subset,vector<vector<int>>& ans,int level){
        if(level >= input.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(input[level]);
        dfs(input,subset,ans,level+1);
        subset.pop_back();
        dfs(input,subset,ans,level+1 );
    }
};


int main(){
    vector<int>s = {2,5,6,9};
    Solution swagg;
    vector<vector<int>> swag = swagg.subsets(s);
    for(int i = 0; i < swag.size(); i++){
        for(int j = 0; j < swag[i].size(); j++){
            cout << swag[i][j] << " ";
        }
        cout << endl;
    }
}