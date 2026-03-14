#include <iostream>
#include <vector>
#include <cmath>
#define ll long long 
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p = 0;
        int q = 0;
        string dump = "";
        cout << word1.length() << endl;
        while(p < word1.length()){

            dump += word1[p];
            if (q < word2.length()){

                dump += word2[p];
                q++;
            }
            
            p++;
        }
        while(q < word2.length()){

            dump += word2[p];
            q++;
        }
       return dump;
    }
};

int main(){
 Solution sol;

 string p = sol.mergeAlternately("ab", "pqrs");
 cout << p << endl;

}