#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
public:
/*
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
*/
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {

       long long count = 0;

       int p = 0;

       while (p <s.length()){
        if (p < s.length() -1 && roman[s[p]] < roman[s[p+1]]){
            count += roman[s[p+1]] - roman[s[p]];
            p+=2;
        } else {
            count += roman[s[p]];
            p++;
        }//IIV
       }
       //1+
          
        
       
       return count;
    }
};

int main(){
    //VII IIV
    Solution s;
    int p = s.romanToInt("IIV");//IIX //M = 1000, CM = 900, XC = 90 and IV = 4.
    cout << p << endl;
}