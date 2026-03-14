#include <iostream>
#include <vector>

#include <stack>


using namespace std;

class Solution {
public:

    bool pembuka(char input){
       return input == '{' || input == '(' || input == '[';
    }

    char convert(char input){

        switch (input){
            case '{':{
                return '}';
            } break;

            case '(': {
                return ')';
            } break;
            return ')';
            case '[': {
                return ']';
            } break;

            default: {
                return '?';
            };
        }
    }
    
    bool isValid(string s) {

        stack<char> temp;

        if(s.length() %2 == 0){

           int i = 0;
           while (i < s.length()){
             cout << "mengecek " << s[i] << endl;
            if (pembuka(s[i])){
                temp.push(s[i]);
            } else {
                if(temp.empty()){
                    return false;
                } else {
                    if(convert(temp.top()) == s[i]){
                        temp.pop();
                    } else {
                        return false;
                    }
                }
            }
            i++;
           
           
           }
           return temp.empty();
        } else {
            return false;
        }
    }
};
//6/2 = 3

int main(){
    Solution s;

    bool lol = s.isValid("()[]{}");//()[]{} //([{}])
    if (lol ){
        cout << "valid" << endl;
    } else {
        cout << "gak valid" << endl;
    }
}