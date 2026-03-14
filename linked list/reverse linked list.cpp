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
//1 2 3
//2 
    while(i < list.size()){
        p->next = new ListNode(list[i]);
        p = p->next;
        i++;
    }
    return temp1.next;
}

class Solution {
public:
   ListNode* reverseList(ListNode* head) {
      ListNode* cur = head;
      ListNode* prev = nullptr;

      while(cur != nullptr){
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      return prev;
   }
};

int main(){
    Solution s;
  //  ListNode* ganteng 
  vector<int> swag = {0,1,2,3};
  ListNode* lol = s.reverseList(createList(swag));
  printList(lol);
}