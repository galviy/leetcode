#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int kanan = nums.size()-1;
        int kiri = 0;
        int p;

        while(kiri <= kanan){
            int mid = (kanan+kiri)/2;
            p = mid;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                kiri =mid+1;
            } else {
                kanan = mid-1;
            }

        }
        cout << kiri << endl;
        cout << kanan << endl;
        cout << p << endl;
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> p = {1,3,5,6};
    int jawaban = s.searchInsert(p,0);
    //cout << jawaban << endl;


}