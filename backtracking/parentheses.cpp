#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string cur;

    vector<string> result;

    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << endl;
        }
        return result;
    }

    void dfs(int buka,int tutup,int n){
        if(buka == n && tutup == n){
            result.push_back(cur);
            return;
        }
        if (buka < n){
            cur += '(';
            dfs(buka+1,tutup,n);
            cur.pop_back();
        }
        if (tutup < buka){
            cur += ')';
            dfs(buka,tutup+1,n);
            cur.pop_back();
        }
    }
};


int main(){
    Solution p;
    int n;
    cin >> n;
    vector<string> l = p.generateParenthesis(n);
}