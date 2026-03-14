#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.length();
        int s2len = s2.length();
        if (s1len > s2len) return false;

        unordered_map<char, int> s1count,s2count;
        for(int i = 0; i < s1len; i++){
            s1count[s1[i]] ++;
            s2count[s2[i]] ++;
        }
        if (s1count == s2count) return true;

        int right = s1.length();
        int left = 0;

        while(right < s2len){
            s2count[s2[right]] ++;
            s2count[s2[left]] --;
            if ( s2count[s2[left]] == 0){
                 s2count.erase(s2[left]);
            }
            if(s1count == s2count) {
                return true;
            }
            right++;
            left++;

        }
        return false;
    }
};

//APE ABPE
int main(){
    Solution s;
    bool ans = s.checkInclusion("abc", "lecabee");
    if (ans) cout << "ya" << endl;
    else 
        cout << "ga" << endl;
}