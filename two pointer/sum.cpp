#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0;
        int p2 = numbers.size() -1;

       while(p < p2){
            if (numbers[p] + numbers[p2] < target){
                p++;
            } else {
                if (numbers[p] + numbers[p2] > target){
                    p2--;
                } else {
                    return {p+1,p2+1};
                }
            }
       }
       return {};
    }
};

int main(){
    vector<int> numbers = {1,2,3,4};
    Solution s;

}