#include <iostream>
#include <vector>

using namespace std;

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