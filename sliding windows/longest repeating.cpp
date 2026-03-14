#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
   

    int characterReplacement(string s, int k) {
         unordered_map<char,int> count;
         int longest = 0;


         int max_val = 0;

         int l = 0;

        for(int r = 0; r < s.length(); r++){
            count[s[r]] ++;
            max_val = max(max_val,count[s[r]]);
            while((r-l +1) -max_val > k){
                 count[s[l]] --;
                 l++;
            }
            longest = max(longest, r-l +1);
        }
        cout << longest << endl;
        return longest;
    }
    
    
};


int main(){
    Solution s;
    int lol = s.characterReplacement("AAABABB",1);

}