#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(rob1(vector<int>(nums.begin() + 1, nums.end())), rob1(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int rob1(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};
int main(){
    vector<int> array = {1,2,3,1};
    vector<int> arrayy = {2,7,9,3,1};
    Solution s;
    int jawaban = s.rob(array);
    cout << jawaban << endl;
}
