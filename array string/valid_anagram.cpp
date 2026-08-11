#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    /*My first solution*/
    /*
    bool isAnagram(string s, string t) {
        unordered_map<char, int> index;
        unordered_map<char, int> index2;

        int size1 = s.length();
        int size2 = t.length();

        for(int i = 0; i < size1; i++){
            if(index.find(s[i]) == index.end()){
                index.insert({s[i], 1}); 
            } else {
                index[s[i]]++;
            }
        }

        for(int i = 0; i < size2; i++){
            if(index2.find(t[i]) == index2.end()){
                index2.insert({t[i], 1}); 
            } else {
                index2[t[i]]++;
            }
        }
        for (auto const& [key, val] : index) {
            if (index[key] != index2[key]){
                return false;
            }
        }
         for (auto const& [key, val] : index2) {
            if (index2[key] != index[key]){
                return false;
            }
        }
        return true;

    }
    */
    /*optimized solution*/
    bool isAnagram(string s, string t) {
        unordered_map<char, int> index;
        int size1 = s.length();
        int size2 = t.length();

        for(int i = 0; i < size1; i++){
            if(index.find(s[i]) == index.end()){
                index.insert({s[i], 1}); 
            } else {
                index[s[i]]++;
            }
        }

        for(int i = 0; i < size2; i++){
           index[t[i]]--;
        }
        for (auto const& [key, val] : index) {
            if (index[key] != 0){
                return false;
            }
        }
       
        return true;

    }
};


int main(){
    Solution s;
    bool jawab = s.isAnagram("jar", "jam");
    cout << jawab << endl;
}
