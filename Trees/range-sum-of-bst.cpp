#include <iostream>
#include <vector>
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
    }
};



int main(){
    TreeNode* pp = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3, new TreeNode(6),new TreeNode(7)));
    TreeNode* z = new TreeNode(3, new TreeNode(1), new TreeNode(2));

    Solution s;

}
