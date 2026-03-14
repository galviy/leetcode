#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
          
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        } while(slow != fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        cout << slow << endl;
        return 1;
    }
};




int main(){
    Solution s;
    vector<int> p = {1,2,3,2,2};
    int p2 = s.findDuplicate(p);
}