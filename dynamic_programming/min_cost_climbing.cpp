#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        if (cost.size() <= 2){
            return min(cost[0],cost[1]);
        }
        int size = cost.size();
        vector<int> dp(size+1,0);
        dp[size-1] = cost[size-1];
        for(int i = size-2; i >= 0; i--){
         
            dp[i] = min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
           
        }
       return min(dp[0],dp[1]);
    } 
};

using namespace std;


int main(){
    vector<int> p = {1,100,1,1,1,100,1,1,100,1};
    Solution s;
    int jawaban = s.minCostClimbingStairs(p);
    cout << jawaban << endl;
}