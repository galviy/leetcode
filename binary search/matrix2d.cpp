#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
       
        cout << r << endl;

        while(l <= r) {
             int mid = (l+r)/2;

            int l2 = 0;
            int r2 = matrix[mid].size()-1;
            bool lebih_kecil;

            while(l2 <= r2){
                 int mid2 = (l2+r2)/2;
                if (matrix[mid][mid2] == target){

                    return true;
                } else {
                    if (matrix[mid][mid2] > target){
                        lebih_kecil = true;
                     
                        r2 = mid2 -1;
                    } else {
                      
                        l2 = mid2 + 1;
                        lebih_kecil = false;

                    }
                }
            }
            if (lebih_kecil){
                r = mid -1;
            } else {
                 l = mid +1;
            }
           
        }
        return false;
    }
};


int main(){
    Solution s;
    vector<vector<int>> swag = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    bool check = s.searchMatrix(swag,99);
    if (check){
        cout << "ketemu" << endl;
    }
}