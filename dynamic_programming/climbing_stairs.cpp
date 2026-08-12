#include <iostream>
#include <vector>

using namespace std;


/*
  int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    Tabulation (buttom up)
*/
class Solution {
public:
    int fibonacci(int n, vector<int>& memo) {
        if (n <= 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        return memo[n];
    }
    int climbStairs(int n) {
          vector<int> memo(n + 1, -1);
        return fibonacci(n,memo);
    }
};

int main(){
    Solution s;
    int p = s.climbStairs(2);
    cout <<p << endl;
}
