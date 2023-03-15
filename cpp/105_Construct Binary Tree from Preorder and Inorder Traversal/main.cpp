/* 105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, 
construct and return the binary tree. 
*/

// Runtime: 23 ms, faster than 71.42% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 26.1 MB, less than 60.45% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

# include <iostream>
# include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* buildTreeKernel(vector<int>::iterator & pre_ptr,
     vector<int>::iterator in_ptr_start, vector<int>::iterator in_ptr_end) {
        if (in_ptr_end - in_ptr_start <= 0) return nullptr;
        TreeNode* node = new TreeNode((*pre_ptr));
        for (vector<int>::iterator in_ptr_mid=in_ptr_start; in_ptr_mid<in_ptr_end; in_ptr_mid++) {
            if ((*in_ptr_mid) == (*pre_ptr)) {
                pre_ptr++;
                node-> left = buildTreeKernel(pre_ptr, in_ptr_start, in_ptr_mid);
                in_ptr_mid++;
                node-> right = buildTreeKernel(pre_ptr, in_ptr_mid, in_ptr_end);
                break;
            }
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int>::iterator pre_ptr=preorder.begin();
        return buildTreeKernel(pre_ptr, inorder.begin(), inorder.end());
    }
};

void output_tree_inorder(TreeNode* node){
    if (node == nullptr) {return; }
    cout << node->val << ' ';
    output_tree_inorder(node->left); output_tree_inorder(node->right);
}

int main() {
    printf("#%s\n\n", "105. Construct Binary Tree from Preorder and Inorder Traversal");
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    Solution s;
    TreeNode* tree_root = s.buildTree(preorder, inorder);
    
    // Output tree.
    output_tree_inorder(tree_root);

    return 1;
}