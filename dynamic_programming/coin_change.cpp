#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

/*
class Solution {
public:
    int calc(vector<int>&coins,int amount,int start){
        int count = 0;
        int temp = 0;
       
        while(start>= 0){
            if(temp + coins[start] == amount) {
                count ++;
                return count;
            } else {
                if(temp + coins[start] < amount){
                    count++;
                    temp+=coins[start];
                } else {
                    start--;
                }
            }
        }
        if(temp != amount) return -1;
        return count;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
      
        for(int i = coins.size()-1; i >= 0; i--){
            int cari = calc(coins,amount,i);
            if(cari != -1) return cari;
        }
        return -1;
    }
};
*/

/*
class Solution {
public:
    int dfs(vector<int>& coins, int left, vector<int>& memo) {
        // Base cases
        if (left == 0) return 0;
        if (left < 0) return -1;
        
        // Return cached result if already calculated
        if (memo[left] != -2) return memo[left];
        
        int min_coins = INT_MAX;
        
        // Try every coin
        for (int i = 0; i < coins.size(); i++) {
            int res = dfs(coins, left - coins[i], memo);
            
            // If a valid combination is found, update the minimum
            if (res != -1) {
                min_coins = min(min_coins, res + 1);
            }
        }
        
        // Cache and return the result (-1 if no combination works)
        memo[left] = (min_coins == INT_MAX) ? -1 : min_coins;
        return memo[left];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Initialize memoization array with -2 (representing unvisited states)
        vector<int> memo(amount + 1, -2);
        return dfs(coins, amount, memo);
    }
};

*/
/*
class Solution {
public:
    int dfs(vector<int>& coins, int left, vector<int>& dp, int count) {

        // Sudah sampai 0
        if (left == 0) {
            dp[left] = count;
            return count;
        }

        // Lewat dari 0
        if (left < 0) {
            return INT_MAX;
        }

        for (int coin : coins) {
            int result = dfs(coins, left - coin, dp, count + 1);

            if (result != INT_MAX) {
                dp[left] = min(dp[left], result);
            }
        }

        return dp[left];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        int ans = dfs(coins, amount, dp, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};
*/

class Solution {
public:
    int dfs(vector<int>& coins, int left,int amount,int step,vector<int>&dp) {
        if(left < 0) return -1;
        if (left == 0)return 0;
        if(dp[left] != INT_MAX) return dp[left];
       
        for(int i = 0; i < coins.size(); i ++){
            int temp = dfs(coins,left-coins[i],amount,step+1,dp);

             if(temp == 0){
               
                if (dp[left] == INT_MAX) {
                    dp[left] = 1;
                   // cout << left << " awal diisi dengan " << dp[left] << endl; 
                } else {
                    dp[left] = temp+1;
                }
            } else {
                if(temp != -1 && temp != INT_MAX){
                   if(dp[left] == INT_MAX) {
                  //  cout << temp << endl;
                        dp[left] = temp + 1;
                    } else {
                        dp[left] = min(dp[left],temp+1);
                    }
                } 
            }
           
        }
        if(dp[left] == INT_MAX) dp[left] = -1;
        return dp[left];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        int ans = dfs(coins, amount,amount,0,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }

};

int main(){
    vector<int> coins = {186,419,83,408};
    Solution p;
    int jawaban = p.coinChange(coins,6249);
    cout << jawaban << endl;
}
