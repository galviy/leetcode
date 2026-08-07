#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();

        int sisa = 0;
        int awal = digits[length-1] + 1;
        if(awal  > 9){
            sisa = 1;
        }

        for(int i = length-1; i >=0 ; i--){
            if(digits[i]+sisa > 9){
                sisa = 1;
                digits[i] = 0;
            } else {
                if(i == length-1){
                    digits[i] += 1;
                } else {
                    if(sisa != 0) digits[i] += sisa;
                    sisa = 0;
                }
                
            }
          
        }
      //  cout << sisa << endl;
        if(sisa != 0){
            digits.insert(digits.begin(),sisa);
        }
        for(int i = 0; i < digits.size(); i++){
            cout << digits[i] << endl;
        }
        
        return {};
    }
};


int main(){
    vector<int> digits = {1,2,3};
    vector<int> digits2 = {4,3,2,1};

    vector<int> digits3 = {9,9,9,9,8,9,9};
    Solution s;
    vector<int> jawaban = s.plusOne(digits3);

}