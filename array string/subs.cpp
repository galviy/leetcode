#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
       int sindex,tindex;
       sindex = 0;
       tindex = 0;
       while (sindex < s.length() && tindex < t.length()){
        if(s[sindex] == t[tindex]){
            sindex++;
            tindex++;
        } else {
            tindex++;
        }
       }
       cout << sindex << endl;
       cout << tindex << endl;
       return sindex ==s.length();
    }
};

int main(){
    Solution s;
    bool lmao = s.isSubsequence("abx", "ahbgdc");
    if (lmao) {
        cout << " ketemu " << endl;
    } else {
        cout << " gak " << endl;
    }
}