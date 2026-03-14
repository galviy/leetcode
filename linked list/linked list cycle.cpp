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
    bool hasCycle(ListNode* head) {
        ListNode* p = head;
        unordered_map<ListNode*, bool>;

        while(p != nullptr){
            p = p->next;
        }
        return false;
    }
};


int main(){
    Solution s;

}