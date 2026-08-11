#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
  vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
            if(index.find(nums[i]) == index.end()){
                index.insert({nums[i], 1}); 
            } else {
                index[nums[i]]++;
            }
        }
        return {};
    }
*/

class Solution {
public:
   struct terbaru{
    int key;
    int val;
   };
   static bool comparecuy(terbaru  a, terbaru b) {
        return a.val > b.val; 
    }
   vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
            if(index.find(nums[i]) == index.end()){
                index.insert({nums[i], 1}); 
            } else {
                index[nums[i]]++;
            }
        }
        vector<terbaru> p;
        vector<int> p2;
        for (auto const& [key, val] : index) {
           p.push_back({key,val});
        }
    
        sort(p.begin(), p.end(), comparecuy);

        for(int i = 0; i < k; i++){
            if(i < p.size()){
                p2.push_back(p[i].key);
            }
        }
        for(int i = 0; i < p.size(); i++){
            cout << p[i].key<< ":" << p[i].val << endl;
        }

        return p2;
    }
};


int main()
{
    Solution p;
    vector<int> aa = {4,1,-1,2,-1,2,3};
    vector<int> jawaban = p.topKFrequent(aa,2);
}