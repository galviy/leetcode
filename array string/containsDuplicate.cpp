#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

    /*
    Optimal solution
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
        
            if(index.find(nums[i]) == index.end()){
            index.insert({nums[i], 1}); 
            } else {
                return true;
            }
        }
        return false;
    }
    */
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> index;
        for(int i = 0; i < nums.size(); i++){
            if(index[nums[i]] == 0){
                index[nums[i]]++;
            }  else {
                return true;
            }
        }
        return false;
    }
};


int main(){

}