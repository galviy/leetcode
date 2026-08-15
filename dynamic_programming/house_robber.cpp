#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

   
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if(nums.size() <= 2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
          
        }
        for(int i = 0; i < dp.size(); i++){
           cout << dp[i] << " ";
        }

        return 1;

    }
};

int main(){
    vector<int> array = {1,2,3};
    vector<int> arrayy = {2,7,9,3,1};
    Solution s;
    int jawaban = s.rob(arrayy);
   // cout << jawaban << endl;
}