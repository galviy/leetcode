#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = 1;
        int cur_area = 0;

        if(heights.size() == 2) {
            return min(heights[0],heights[1]);
        }
        for(int i = 2; i < heights.size(); i++){
            cur_area = (p2-p1)*min(heights[p1],heights[p2]);
            //cout <<" cur area " << cur_area << endl;
             
            if(heights[i] > heights[p2]){
                if ( (i-p2)*min(heights[p2],heights[i]) >= (i-p1)*min(heights[p1],heights[i])){
                     p1=p2;
                     p2 = i;
                } else {
                     p2 = i;
                }

            }
           else {
            
            if(heights[i] > heights[p1]){
                
                if ( (i-p2)*min(heights[p2],heights[i]) >= (i-p1)*min(heights[p1],heights[i])){
                    printf("Membandingkan (%d,%d), (%d,%d)",p2,i,p1,i);
                    cout << "anjg"  << endl;
                     p1=p2;
                     p2 = i;
                } else {
                    p2 = i;
                }
               
            } else {
                if(cur_area < (i-p1)*min(heights[p1],heights[i])){
                  p2 = i;
                  cur_area =  (i-p1)*min(heights[p1],heights[p2]);
                }
            }
           // if (heights[i] < heights[p2])
           }
           cout  << p1 <<  " " << p2 << endl;
          // cout << heights[p1] << " dan " << heights[p2] << endl;
          cout << (i-p1)*min(heights[p1],heights[p2]) << endl;
        }
        
        return (p2-p1)*min(heights[p1],heights[p2]);
    }
};


int main(){
    Solution s;
    vector<int> lol = {2,3,10,5,7,8,9};
    int p = s.maxArea(lol);
}