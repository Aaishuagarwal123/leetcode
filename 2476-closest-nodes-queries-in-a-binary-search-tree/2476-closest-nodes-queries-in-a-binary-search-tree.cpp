/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  vector<int> find(TreeNode* root, int key) {  
    int mini=-1;
    int maxi=-1;
    while(root!=NULL)
    {
        if(root->val==key)
        return {root->val,root->val};
        if(root->val<key)
        {
          mini=root->val;
        root=root->right;}
        else
        {
            maxi=root->val;
            root=root->left;
        }
        
    }
    return {mini,maxi};
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
      for(auto q:queries)
      {
        ;
        ans.push_back(find(root,q));
      }
      return ans;
    }
};