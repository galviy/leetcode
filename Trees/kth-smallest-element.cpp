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
   
    PrintTree(tree->left,kedalaman+1);
     cout << tree->val << endl;
    PrintTree(tree->right,kedalaman+1);
}
    
class Solution {
public:
    vector<int> s;
    void insert(TreeNode* tree){
        if(tree == nullptr) return;
        insert(tree->left);
        s.push_back(tree->val);
        insert(tree->right);
    }
    int kthSmallest(TreeNode* root, int k) {
       
        insert(root);
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << endl;
        }
        cout << "anjing" << endl;
        return 1;
    }
};



int main(){
    TreeNode* pp = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3, new TreeNode(6),new TreeNode(7)));
    //new TreeNode(3, new TreeNode(6),new TreeNode(7))
    TreeNode* z = new TreeNode(3, new TreeNode(1,nullptr,new TreeNode(2)), new TreeNode(4));
    Solution s;
    int p = s.kthSmallest(z,0);
  //  cout << p << endl;
    //PrintTree(p,0);

}
