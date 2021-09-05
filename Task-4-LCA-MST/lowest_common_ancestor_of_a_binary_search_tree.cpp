
/*
    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> *getAncestry(TreeNode* root, TreeNode* node) {
        TreeNode *curr = root;
        vector<TreeNode*> *ancestry = new vector<TreeNode*>();
        while (true) {
            ancestry->push_back(curr);
            if (curr == node) break;
            if (node->val > curr->val) curr = curr->right;
            else curr = curr->left;
        }
        return ancestry;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> *curr = getAncestry(root, p);
        vector<TreeNode*> *toSet = getAncestry(root, q);
        unordered_set<TreeNode*> s;
        if (curr->size() < toSet->size()) {
            vector<TreeNode*> *temp = curr;
            curr = toSet;
            toSet = temp;
        }
        for (TreeNode* i : *toSet) s.insert(i);
        for (int i = curr->size() - 1; i >= 0; i--) {
            if (s.find((*curr)[i]) != s.end()) return (*curr)[i];
        }
        return p;
    }
};