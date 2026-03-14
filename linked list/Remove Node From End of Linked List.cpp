#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
    
        ListNode* p2 = head;
        ListNode* p3 = head;


        int counter = 0;
        int index = 0;
        while(p !=nullptr){
            counter++;
            p = p->next;

        }

        ListNode* prev = nullptr;
        while(p2 != nullptr){
            index++;
            
         
            if (index == counter-n+1){
               
              
                 ListNode* next = p2->next;
                 if (prev == nullptr){


                    return next;
                 } else {
                     prev->next =  prev->next->next;
                      p2 = next;
                 }
                
               //  prev->next = p2->next->next;
                             

            } else {
                 prev = p2;
                p2 = p2->next;
            }

        }

        return head;
    }
};




int main(){
    vector<int> s = {1,2};
    ListNode* input = createList(s);
    //printList(input);
    Solution spp;
    ListNode* p = spp.removeNthFromEnd(input,2);
    printList(p);

}