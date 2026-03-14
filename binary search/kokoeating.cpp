#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

            
        
        
        int max = -999;

        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int l = 1;
        int r = max; 

        int best = max;

        while (l <= r) {
            int mid = (l + r) / 2;
            int temp = 0;

            for (int i = 0; i < piles.size(); i++) {
                temp += (piles[i] + mid - 1) / mid;
            }

            if (temp <= h) {
                best = mid;
                r = mid - 1;  
            } else {
                l = mid + 1;   
            }
        }
        cout << best << endl;

        return best;
    }
};
//[1,4,3,2], h = 9

// 1/2 = 0.5 -> 1
// 4/2 = 2 -> 2
//3/2 = 1.5 -> 2
//1/2 = 0.5 -> 1
// 2 banana 1 jam
//1
//2
//2
//1
//6

//1/1 = 1
//4/1 = 4
//3/1 = 3
//2/1 = 1
//10




int main(){

    vector<int> pileee = {25,10,23,4};
    Solution s;
    int p = s.minEatingSpeed(pileee,4);
}