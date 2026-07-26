#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isTreeSymmetric(TreeNode* leftr,TreeNode* rightr){
        if(leftr == nullptr && rightr == nullptr){
            return true;
        }
        if ((leftr == nullptr && rightr != nullptr) || (leftr != nullptr && rightr == nullptr)){
            return false;
        }
        if(leftr->val != rightr->val){
            return false; 
        }
        return isTreeSymmetric(leftr -> left, rightr -> right) && isTreeSymmetric(leftr -> right, rightr -> left);
    }
    bool isSymmetric(TreeNode* root) { 
        return isTreeSymmetric(root->left, root->right);  
    }
};