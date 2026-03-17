#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];

        int p1 = stones.size()-1;

        while(p1 > 0 ){
            sort(stones.begin(), stones.end());
            if(stones[p1] == stones[p1-1]){
                stones.pop_back();
                stones.pop_back();
                p1 = p1-2;
            } else {
                int selisih = abs(stones[p1] - stones[p1-1]);

                stones.pop_back();
                stones[stones.size()-1] = selisih;
                p1 = p1-1;
            }

        }
        cout << stones[stones.size()-1] << endl;

        return  stones[stones.size()-1];
    }
};

int main(){
    vector<int> p = {2,3,6,2,4};
    Solution p2;
    int p3 = p2.lastStoneWeight(p);
}
