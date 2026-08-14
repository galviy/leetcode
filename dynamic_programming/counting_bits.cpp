#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
Optimal solution
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i / 2] + (i % 2);
        }
        
        return dp;
    }
};
*/

class Solution {
public:
    string cetakBiner(int n, unordered_map<int, string> &dp) {
    
        if (n == 0) return "0";
        if (n == 1) return "1";
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        string hasil = cetakBiner(n / 2, dp) + to_string(n % 2);
        dp[n] = hasil;
        return hasil;
    }

    vector<int> countBits(int n) {
        vector<int> temp;
        unordered_map<int,string> dp;
        for(int i = 0; i <= n; i++){
            string pp = cetakBiner(i,dp);
            int counter = 0;
            for(int i = 0; i < pp.length(); i++){
                if(pp[i] == '1') counter++;
            }
            temp.push_back(counter);
        }
        return temp;
    }
};


int main(){
    Solution s;
    vector<int> jawab = s.countBits(5);
    for(int i = 0; i < jawab.size(); i++){
        cout << jawab[i] << endl;
    }
}