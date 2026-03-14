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
    void traversal(TreeNode* root,int level){
        if (root == nullptr) return;
        cout << root->val << " dengan level " << level <<endl;
       if(temp.size() == level){
        temp.push_back(root->val);
       } else {
        temp[level] += root->val;
       }
        traversal(root->right,level+1);
        traversal(root->left, level+1);
    }
     int maxLevelSum(TreeNode* root) {
        traversal(root,0);
        int max_val = -999;
        int lvl = 0;
        for(int i = 0; i < temp.size(); i++){
           if(max_val < temp[i]){
            max_val = temp[i];
            lvl = i;
           }
        }
        return lvl+1;
    }
};


int main(){
    TreeNode* pp = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3, new TreeNode(6),new TreeNode(7)));
    TreeNode* z = new TreeNode(1, new TreeNode(7,new TreeNode(7),new TreeNode(-8)), new TreeNode(0));
    //PrintTree(pp,0);
    Solution s;
    int p = s.maxLevelSum(z);
    cout << p << endl;
}
