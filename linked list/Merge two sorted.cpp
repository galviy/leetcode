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
    void insertvlast(ListNode* &list1 , int val){
        
        if (list1 == nullptr){
            list1 = new ListNode(val);

        } else {
            ListNode* p = list1;
            while(p->next != nullptr){
                p = p->next;
            }

            p->next = new ListNode(val);
        }
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        ListNode* temp = nullptr;

        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val > cur2->val){
                insertvlast(temp,cur2->val);
                cur2 = cur2->next;
            } else {
                insertvlast(temp,cur1->val);
                cur1 = cur1->next;
            }
        }
        while(cur1 != nullptr){
             insertvlast(temp,cur1->val);
             cur1 = cur1->next;
        }
        while(cur2 != nullptr){
             insertvlast(temp,cur2->val);
             cur2 = cur2->next;
        }
        return temp;
    }
};


int main(){
    Solution s;
    vector<int> swag = {1,2,3};
    vector<int> swag2 = {1,2,4};

    ListNode* ans = s.mergeTwoLists(createList(swag), createList(swag2));
  // ListNode* lol = createList(swag);
   //s.insertvlast(lol,1);
   printList(ans);
  //  Solution s;
    //ListNode* ans = s.mergeTwoLists(createList(swag),createList(swag2));

}