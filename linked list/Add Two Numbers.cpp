#include <iostream>
#include <string>

#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void printList(ListNode* input){
    ListNode *p = input;
    while(p != nullptr){
        cout << p->val << endl;
        p = p->next;
    }

}
ListNode* createList(vector<int> list){
    ListNode temp1;
    ListNode* p = &temp1;
    int i = 0;

    while(i < list.size()){
        p->next = new ListNode(list[i]);
        p = p->next;
        i++;
    }

    return temp1.next;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        int lengthp1 = 0;
        int lengthp2 = 0;

        while(p1 != nullptr || p2 != nullptr){
            if(p1 != nullptr){
                lengthp1++;
                 p1 = p1->next;
            }
            if(p2 != nullptr){
                lengthp2++;
                p2 = p2->next;
            }

        }

        p1 = l1;
        p2 = l2;

        if(lengthp1 > lengthp2){
            ListNode* last = nullptr;
            while(p2 != nullptr){
                int sum = p1->val + p2->val + carry;
                int digit = sum%10;
                carry = sum/10;

                p1->val = digit;

              last = p1;
              p1 = p1->next;
              p2 = p2->next;
            }
            while(p1 != nullptr && carry > 0){
                int sum = p1->val + carry;
                p1->val = sum % 10;
                carry = sum / 10;
                last = p1;
                p1 = p1->next;
                }
            if(carry > 0){
                last->next = new ListNode(carry);
            }
         
            return l1;

        } else {
            if (lengthp1 < lengthp2){ 
                 ListNode* last = nullptr;
                while(p1 != nullptr){
                    int sum = p1->val + p2->val + carry;
                    int digit = sum%10;
                    carry = sum/10;

                    p2->val = digit;
                    last = p2;
                    p1 = p1->next;
                    p2 = p2->next;
                }
               while(p2 != nullptr && carry > 0){
                    int sum = p2->val + carry;
                    p2->val = sum % 10;
                    carry = sum / 10;
                    last = p2;
                    p2 = p2->next;
                }
                if(carry > 0){
                     last->next = new ListNode(carry);
                }
                return l2;

            } else { //length equal
                ListNode* last = nullptr;
                 while(p1 != nullptr){
                    int sum = p1->val + p2->val + carry;
                    int digit = sum%10;
                    carry = sum/10;

                    p1->val = digit;
                    last = p1;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                if(carry >0){
                     last->next = new ListNode(carry);
                }

                return l1;
            }
        }
       //printList(l1);
     

    }
};



int main(){
    Solution s;
    vector<int>p = {8,9};
    vector<int> p2 = {9};

    ListNode* l1 = createList(p);
    ListNode* l2 = createList(p2);
    ListNode* ans = s.addTwoNumbers(l1,l2);
    printList(ans);
}

