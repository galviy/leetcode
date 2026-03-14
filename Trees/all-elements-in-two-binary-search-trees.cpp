#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void PrintTree(TreeNode* tree,int kedalaman){
    if(tree == nullptr) return;
    
    for(int i = 0; i < kedalaman; i++){
        cout << ".";
    }
   
    PrintTree(tree->left,kedalaman+1);
     cout << tree->val << endl;
    PrintTree(tree->right,kedalaman+1);
}
    
class Solution {
public:

    void inorder(TreeNode* root) {
        stack<TreeNode*> p;
        while(root != nullptr || !p.empty()){
            while(root != nullptr){
                 p.push(root);
                 root = root->left;
            }
            root = p.top();
            p.pop();
            cout << root->val << " ";
            root = root->right;
        }
    }
    

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stek;
        stack<TreeNode*> stek2;
        vector<int> s;
        while(root1 != nullptr || root2 != nullptr || !stek.empty() || !stek2.empty()){
                while(root1 != nullptr){
                    stek.push(root1);
                    root1 = root1->left;
                }
                while(root2 !=nullptr){
                    stek2.push(root2);
                    root2 = root2->left;
                }
        }
      

       return {};
    }
};



int main(){
    TreeNode* pp = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3, new TreeNode(6),new TreeNode(7)));
    //new TreeNode(3, new TreeNode(6),new TreeNode(7))
    TreeNode* z = new TreeNode(3, new TreeNode(1,nullptr,new TreeNode(2)), new TreeNode(4));
    Solution s;
    TreeNode* p1 = new TreeNode(2, new TreeNode(1), new TreeNode(4));
    TreeNode* p2 = new TreeNode(1, new TreeNode(0), new TreeNode(3));

  //  vector<int> p = s.getAllElements(p1,p2);
    s.inorder(pp);
   // PrintTree(p1,0);

}
