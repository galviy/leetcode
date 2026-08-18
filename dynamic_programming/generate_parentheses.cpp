#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> ans;
    /*
    class Solution {
public:
    vector<string> ans;
    string stackToString(std::stack<std::string> s) {
        string result = "";

        while (!s.empty()) {
            result = s.top() + result; 
            s.pop();
        }
        return result;
    }

    void generate(stack<string> p,int open,int close,int n){
        if(open == close){
            if(open == n){
                string aaa = stackToString(p);
                ans.push_back(aaa);
                return;
            }
            p.push("(");
            generate(p,open+1,close,n);
            return;
        }
        if (open == n){
            p.push(")");
            generate(p,open,close+1,n);
            return;
        }
        if(open > close){
            stack<string> p1 = p;

            p1.push("(");
            generate(p1,open+1,close,n);

            stack<string> p2 = p;
            p2.push(")");
            generate(p2,open,close+1,n);

        }
    }

    vector<string> generateParenthesis(int n) {
      stack<string> pp;
      int open = 0;
      int close = 0;
      generate(pp,open,close,n);
        return ans;
    }
};
    */
    void generate(string& p,int open,int close,int n){
        if (open == n && close == n) {
            ans.push_back(p);
            return;
        }

        if (open == close) {
            p.push_back('(');
            generate(p, open + 1, close, n);
            p.pop_back();
            return;
        }

        if (open == n){
            p.push_back(')');
            generate(p,open,close+1,n);
            p.pop_back();
            return;
        }
        if(open > close){
            string p1 = p;

            p1.push_back('(');
            generate(p1,open+1,close,n);

            string p2 = p;
            p2.push_back(')');
            generate(p2,open,close+1,n);

        }
    }

    vector<string> generateParenthesis(int n) {
    string pp;

      generate(pp,0,0,n);
        return ans;
    }
};
    
    
    

int main(){
    Solution p;
    vector<string> answerr = p.generateParenthesis(3);
    for(int i = 0; i < answerr.size(); i++){
        cout << answerr[i] << endl;
    }

}