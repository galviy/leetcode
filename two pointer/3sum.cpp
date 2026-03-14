#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void bubble_sort(vector<int>& nums){
        for(int i = 0; i < nums.size()-1 ; i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] > nums[j]){
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
      
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> temp;
       
        bubble_sort(nums);

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
           
            if (i > 0 && nums[i] == nums[i - 1]) continue;
             int l = i + 1;
            int r = nums.size() - 1;
            while (l < r){
                if (nums[l] + nums[r] + nums[i] == 0){
                    cout << " sama dengan 0 " << nums [i] << " " << nums[r] << " " << nums[i] << endl;
                    temp.push_back({nums[i], nums[l], nums[r]});

                      l++;
                      r--;
                      while(l < r && nums[l] == nums[l-1]){
                        l++;
                      }
                } else {
                    if(nums[l] + nums[r] + nums[i]> 0){
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return temp;
    }
};




int main(){
    Solution s;
    vector<int> data = {0,1,1};
    vector<vector<int>> swag = s.threeSum(data);
}