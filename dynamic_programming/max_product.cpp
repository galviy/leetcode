
#include <bits/stdc++.h>
using namespace std;


/*
class Solution {
public:
    int minn = INT_MIN;
    void dfs(vector<int>& nums,vector<bool> &visited,int i,int temp){
        if(i <  0) return; 
        if(i >= nums.size()) return;
        if(visited[i]) return;
        visited[i] = true;
        temp*=nums[i];
        minn = max(minn,temp);

        dfs(nums,visited,i+1,temp);
        dfs(nums,visited,i-1,temp);
        visited[i] = false;

    }

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1]*nums[0],max(nums[1],nums[0]));
        for(int i = 0; i < nums.size(); i++){
            vector<bool> visited(nums.size(), false);
            cout << "memulai i " << i << endl;
            dfs(nums,visited,i,1);
        }
        return minn;
      
    }
};

*/
class Solution {
public:
    int minn = INT_MIN;
    void dfs(vector<int>& nums,int i,int temp){
        if(i >= nums.size()) return;
        temp*=nums[i];
        minn = max(minn,temp);
        dfs(nums,i+1,temp);
    }

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1]*nums[0],max(nums[1],nums[0]));
        for(int i = 0; i < nums.size(); i++){
            cout << "memulai i " << i << endl;
            dfs(nums,i,1);
        }
        return minn;
      
    }
};



int main(){
    vector<int> pp = {2,4,-3,5};
    Solution p;
    int jawaban = p.maxProduct(pp);
    cout << jawaban << endl;
}