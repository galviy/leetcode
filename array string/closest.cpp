#include <iostream>
#include <vector>
#include <cmath>
#define ll long long 
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        long long longest = 999999;

        for(int i = 0; i < nums.size(); i++){
            
            if(abs(0-nums[i]) < abs(longest)){
                longest = nums[i];
               
            } else {
                if (abs(longest) == abs(0-nums[i]) && longest < nums[i]){
                    longest = nums[i];
                }
            }
        }

        return longest;
    }

};

int main(){
 Solution sol;
 vector<int> test = {-4,-2,-1,4,8,1};
 int p = sol.findClosestNumber(test);
 cout << p << endl;
}