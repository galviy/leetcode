#include <iostream>
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
    cout << tree->val << endl;
    PrintTree(tree->left,kedalaman+1);
    PrintTree(tree->right,kedalaman+1);
}

class Solution {
public:
    int maxDepth(TreeNode* root){
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(abs(maxDepth(root->right)-maxDepth(root->left)) <= 1){
            return true;
        }
        return false;
    }
};


int main(){
    Solution s;
    TreeNode* P = new TreeNode(3, new TreeNode(9), new TreeNode(20,new TreeNode(15), new TreeNode(7)));//;
  //  PrintTree(P, 0);
  bool p = s.isBalanced(P);
  if(p) cout << "balance" << endl;
  else cout << "gak " << endl;
}
