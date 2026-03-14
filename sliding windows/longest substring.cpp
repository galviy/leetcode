#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best_length = 0;
        string temp = "";
       

        for(int i = 0; i < s.length(); i++){

            if(temp.find(s[i]) != string::npos){


                int pos = temp.find(s[i]);
                if(pos == 0){
                     temp.erase(temp.begin() + pos);
                     temp+= s[i];
                } else {
                    temp = s[i];
                }
              //  cout << "telah ditemukan " << s[i] << " di " << pos << endl;
               
  
            }else {
                // cout << s[] << " bukan substring" << endl;
                temp += s[i];
                 if(temp.length() > best_length){
                    best_length++;
                 }
                
            }
           cout << temp << endl;
        }

        cout << best_length << endl;
        return 1;
    }
};



int main(){
    Solution s;
    int swag = s.lengthOfLongestSubstring("pwwkew");
}           
