/* 144. Binary Tree Preorder Traversal
Easy

Given the root of a binary tree, return the preorder traversal of its nodes' values. */

// Runtime: 6 ms, faster than 21.52% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.3 MB, less than 76.05% of C++ online submissions for Binary Tree Inorder Traversal.

# include <iostream>
# include <vector>
# include <queue>
# include <stack>

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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> sn;
        TreeNode* crt = root;

        while(crt || !sn.empty()) {
            if (crt) {
                sn.push(crt);
                crt = crt->left;
            }
            else {
                crt = sn.top();
                sn.pop();

                res.push_back(crt->val);
                crt = crt->right;
            }
        }

        return res;
    }
};

// Construct a binary tree from level traversal vector recursively.
TreeNode* constructTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root;
    root = new TreeNode(nums[0]);
    q.push(root);
    int index = 1;
    while(index < nums.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (nums[index]) {
            node->left = new TreeNode(nums[index]);
            q.push(node->left);
        }
        index++;
        if (index >= nums.size()) break;
        if (nums[index]) {
            node->right = new TreeNode(nums[index]);
            q.push(node->right);
        }
        index++;
    }
    return root;
}


template <typename T>
void print_vector(vector<T>& nums) {
    cout << "[ ";
    for (auto n: nums) {
        cout << n << ' ';
    }
    cout << ']';
}


int main() {
    // Inputs.
    vector<int> root_vector = {1, NULL, 2, 3};
    TreeNode* root = constructTree(root_vector);

    // Solution.
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    print_vector(result); cout << endl;

    return 0;
}