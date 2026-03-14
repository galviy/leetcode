#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;

        dfs(nums, cur,0,target,0 );
        return result;
    }

    void dfs(vector<int>input,vector<int>& cur,int sum_total,int target,int index){
       
        if(sum_total == target){
            result.push_back(cur);
            return;
        }
      
        if(sum_total > target || index >= input.size()){
            return;
        }
        cur.push_back(input[index]);

        dfs(input,cur,sum_total + input[index],target,index);
        cur.pop_back();
        dfs(input,cur,sum_total,target,index+1);
    }
};



int main(){
    vector<int> p = {2,5,6,9};

    Solution s;
    vector<vector<int>> pp = s.combinationSum(p,9);

    for(int i = 0; i < pp.size(); i++){
        for(int j = 0; j < pp[i].size(); j++){
            cout << pp[i][j] << " ";
        }
        cout << endl;
    }
}