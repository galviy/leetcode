#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int i = 0; 
        int j = 1;
        vector<int> temp;
        while (i < temperatures.size()){
           // cout << "index i " << i << ", j " << j;
             //cout << " Membandingkan " << temperatures[i] << " dengan " << temperatures[j] << endl;
            
             if(j < temperatures.size()){
                 cout << "index i " << i << ", j " << j;
                cout << " Membandingkan " << temperatures[i] << " dengan " << temperatures[j] << endl;
                if(temperatures[i] < temperatures[j]){
                    temp.push_back(j-i);
                    
                     cout << temperatures[i] << " >" << temperatures[j] << endl;
                    i++;
                    j = i+1;
                    
            
                } else {
                     j++;
                }
            
            } else {
                 cout << "index i " << i << ", j " << j;
              //  cout << " Membandingkan " << temperatures[i] << " dengan " << temperatures[j] << endl;
                //cout << "anjkg co " << endl;
                temp.push_back(0);
                i++;
                j = i+1;
            }
           
           
        }
        // temp.push_back(0);
        return temp;
    }
};


using namespace std;

int main(){
    Solution a;
    vector<int> s = {30,40,50,60};
    vector<int> swag = a.dailyTemperatures(s);
}