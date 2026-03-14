#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = 999999;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < smallest) {
                smallest = profit;
            } else {
                if(profit > prices[i] - smallest){
                    profit = prices[i] - smallest;
                }
            }
        }
    }
};

int main(){

}