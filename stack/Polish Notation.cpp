#include <iostream>
#include <stack>
//
#include <vector>

using namespace std;

class Solution {
public:


    int evalRPN(vector<string>& tokens) {
        stack<int> angka;
        int result = 0;

        int i = 0;

        while(i < tokens.size()){

            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i]== "*"){
                int second = angka.top();
                angka.pop();
                cout << "Mengeluarkan " << second << endl;
                int first = angka.top();
                angka.pop();
                 cout << "Mengeluarkan " << first << endl;
                switch(tokens[i][0]){
                    case '+': {
                        result = first+ second;
                    } break;
                    case '-':{
                        result = first-second;
                    } break;
                    case '/': {
                        cout << "membagi " << first << " dengan " << second << endl;
                        result = first/second;
                    } 
                    case '*': {
                        result = first*second;
                    }
                }
                cout << "Hasil sementara " << result << endl;
                angka.push(result);
            } else {
                angka.push(stoi(tokens[i]));
            }
            i++;
        }
        cout << result << endl;
        return result;
    }
};


int main(){
    vector<string> arrr = {"4","13","5","/","+"};
    Solution s;
    int swag = s.evalRPN(arrr);
}