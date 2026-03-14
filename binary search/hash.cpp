#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class hashSearch{
   public:
    bool berapaBanyakX(int x,vector<int>list){
        unordered_map<int,int> counter;

        for(int i = 0; i < list.size(); i++){
            counter[list[i]]++;
        }

        return counter[x] > 0;

    }
};

int main(){
    vector<int> search = {1,3,4,5,6};
    hashSearch s;
    bool swag = s.berapaBanyakX(2,search);
    if (swag){
        cout << "ketemu" << endl;
    } else {
        cout << "gak " << endl;
    }
}