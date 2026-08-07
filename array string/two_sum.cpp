#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    /*
    Naive approach O(N^2)
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for(int i = 0; i < nums.size(); i++){
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target){
                        return {i,j};
                    }
                }
            }
            return {};
        }
    };
    
    */

    /*Optimal O(N) Solution */
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> index;
        for(int i = 0; i < nums.size(); i++){
           if(index[target-nums[i]] == 0){
            cout << "index ke " << nums[i] << " diset ke " << i+1 << endl;
            index[nums[i]] = i+1;
           }
           else {
            cout << target << " dikurang " << nums[i]  << " sama dengan tidak nol"<< endl;
            return {index[target-nums[i]]-1,i};
           }
        }
        return {};
    }
};


int main(){
    Solution pp;
    vector<int> a = {2,7,11,15};
    vector<int> b = {3,2,4};
    vector<int> c = {3,3};

    vector<int> jawaban = pp.twoSum(b,6);

}