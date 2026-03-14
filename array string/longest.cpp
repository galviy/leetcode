#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

   string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    int p = 0;
    string ans = "";

    while (true) {
        // cek batas string pertama
        if (p >= strs[0].length()) break;

        int counter = 0;

        for (int i = 1; i < strs.size(); i++) {
            if (p >= strs[i].length()) {
                return ans;
            }
            if (strs[i][p] == strs[0][p]) {
                counter++;
            }
        }

        if (counter == strs.size() - 1) {
            ans += strs[0][p];
            p++;
        } else {
            break;
        }
    }

    return ans;
}

};


/*
class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
       if (strs.size() == 1) return strs[0];

       int p = 0;
       string ans = "";
       bool checker = true;
       
       while(checker){
        //strs[]
        int counter = 0;
        for(int i = 1; i < strs.size(); i++){
              checker = false;
           if (p < strs[i].length() && p < strs[0].length()) {
                if (strs[0][p] == strs[i][p] && strs[i].length()-1 > i){
                    cout << " ada anjing " << endl;
                    counter++;
                    checker = true;
                }
                
            } 
            
            
        }

        if (checker && counter == strs.size()-1 ){
            ans += strs[0][p];
        }
        p++;
       }

       return ans;
    }

};
*/
int main(){
 Solution sol;

 vector<string> test = {"ab", "a"};
 string p = sol.longestCommonPrefix(test);
 cout << p << endl;
}