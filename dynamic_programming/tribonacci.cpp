#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(1);
        for(int i = 3; i <= n; i++){
            dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
           // cout << dp[i] << endl;
        }
        return dp[n];
    }

};

using namespace std;

int main(){
    Solution p;
    int jawab = p.tribonacci(6);
    cout << jawab << endl;
}