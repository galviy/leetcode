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
    vector<int> temp;
    
    void traversal(TreeNode* root, int kedalaman){
        if(root == nullptr) return;
        
        if(temp.size() == kedalaman){
         
            temp.push_back(root->val);
        } else {
            temp[kedalaman] += root->val;
        }
        traversal(root->right, kedalaman+1);
        traversal(root->left,kedalaman + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        traversal(root,0);
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i] << endl;
        }
        return temp[temp.size()-1];
    }
};


int main(){
    TreeNode* pp = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3, new TreeNode(6),new TreeNode(7)));
    TreeNode* z = new TreeNode(1, new TreeNode(2, new TreeNode (4, new TreeNode(7), nullptr),new TreeNode(5)), new TreeNode(3,nullptr, new TreeNode(6,nullptr,new TreeNode(8))));
  //  PrintTree(z,0);
    Solution s;
    int p = s.deepestLeavesSum(z);
    cout << p << endl;
}
