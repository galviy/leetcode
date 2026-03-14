#include <iostream>
#include <vector>
#include <unordered_map>
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
    void reorderList(ListNode* head) {
        ListNode* P = head;

        int index = 0;
        int new_length = 0;

        while(P != nullptr){
            P = P->next;
            index++;
        }

        P = head;
       
        new_length = index/2;
       // cout << new_length << endl;
        index = 0;
        int p1 = 0;

        ListNode* list1 = nullptr;
        ListNode* s = nullptr;
        ListNode* list2 = nullptr;

        //ListNode 
        while(P != nullptr){
          
            if (index >= new_length){

                ListNode* next = P->next;
                
                P->next = list2;
                list2 = P;

                P = next;
            } else {

               if(list1 == nullptr){
                list1 = P;
                s = list1;
               } else {
                list1->next =P;
                list1 = list1->next;
               }
                P = P->next;
                 list1->next = nullptr;
            }

            index++;
        }
       
        ListNode* awal = s;    
        ListNode* akhir = list2; 
        while(awal!=nullptr && akhir!= nullptr){
            ListNode* tmp1 = awal->next; 
            ListNode* tmp2 = akhir->next;
            awal->next = akhir;
            if (tmp1 == nullptr) break;
            akhir->next = tmp1;
            awal = tmp1;
            akhir = tmp2;
        }
        printList(head);

 
    }
};


int main(){
    Solution s;
    vector<int> listt = {0, 1, 2, 3, 4, 5, 6};
    ListNode* test = createList(listt);
    s.reorderList(test);
}