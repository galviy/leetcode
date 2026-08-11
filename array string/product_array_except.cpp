#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int total = 1;
        int zeroCounter = 0;
        vector<int> j;

        bool hasZero = false;
        bool allZero = true;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zeroCounter++;
                hasZero = true;
                continue;
            } 
            allZero = false;
            total = total*nums[i];
        }
        if (allZero) return nums;
        if (zeroCounter > 1){
            vector<int> v(nums.size(), 0); 
            return v;
        }
        for(int i = 0; i < nums.size(); i++){
            if(hasZero){
                if(nums[i] != 0) j.push_back(0);
                else  j.push_back(total);
            }
            else j.push_back(total/nums[i]);
        }
        return j;
    }
};

int main(){
    Solution s;
    vector<int> p = {-1,1,0,-3,3};
    vector<int> jawaban = s.productExceptSelf(p);
    for(int i = 0; i < jawaban.size(); i++){
        cout << jawaban[i] << endl;
    }
  //  int jawaban = s.searchInsert(p,0);
    //cout << jawaban << endl;


}