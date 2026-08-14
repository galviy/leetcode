#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  vector<vector<int>> generate(int numRows) {
     // if (numRows == 1) return {{1}};
      //if (numRows == 2) return {{1},{1,1}};
      vector<vector<int>> jawaban;
      jawaban.push_back({1});
      jawaban.push_back({1,1});
      for(int i = 2; i < numRows; i++){
        vector<int> temp;
         for(int j = 0 ; j <  jawaban[i-1].size()-1;j++){
          //cout << jawaban[i-1][j] + jawaban[i-1][j+1] << " ";
          temp.push_back(jawaban[i-1][j] + jawaban[i-1][j+1]);
          }
          temp.insert(temp.begin(),1);
          temp.push_back(1);
          jawaban.push_back(temp);

          //cout << endl;
      }

        return jawaban;
    }
};


int main(){
    int input = 5;
    Solution s;
    vector<vector<int>> p = s.generate(5);
    for(int i = 0; i < p.size(); i++){
      for(int j = 0; j < p[i].size(); j++){
        cout << p[i][j] << " ";
      }
      cout << endl;
    }
}