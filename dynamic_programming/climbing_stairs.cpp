#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution {
public:
    ll fibonacci(ll n, vector<ll>& memo) {
        if (n <= 1)
            return 1;

        if (memo[n] != -1)
           return memo[n];

        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        return memo[n];
    }
    ll climbStairs(ll n) {
          vector<ll> memo(n + 1, -1);
        return fibonacci(n,memo);
    }
};

/*
class Solution {
public:

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
};
*/

int main(){
    Solution s;
    ll p = s.climbStairs(100);
    cout <<p << endl;
}