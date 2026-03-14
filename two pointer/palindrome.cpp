#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;

        string concat = "";

        for (char c : s) {
            if (isalnum((unsigned char)c)) {
                concat += tolower((unsigned char)c);
            }
        }
 
        if(concat.length() == 0) return true;

        int start= 0;
        int akhir = concat.length()-1;
        bool check = true;

        if(akhir %2 == 0) {
           
            while(check && start < (concat.length()-1) /2 && akhir > (concat.length()-1)/2){
                if (concat[start] != concat [akhir]){
                    check = false;
                    break;
                } else {
                    
                }
                start++;
                akhir--;
            }
           
        } else {
              while(check && start <= (concat.length()-1) /2 && akhir >= ((concat.length()-1) /2)+1){
                if (concat[start] != concat [akhir]){
                    check = false;
                    break;
                }
                start++;
                akhir--;
            }
           
        }

        return check;

        
    }
};


int main(){
    Solution s;
    bool lmao = s.isPalindrome(".,");
    if(lmao){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

}