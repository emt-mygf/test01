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

 //题目中的二叉树层序遍历结果得到二叉树的话，用队列实现，反过来也是用队列
 //栈递推实现
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        
        //根节点的最左支进栈
        while(root->left != nullptr){
            root = root->left;
            s.push(root);
        }
        TreeNode* ori_root = root;
        
        if(s.empty()) return ori_root;
        s.pop();

        //当前节点为最左（小）的点，无左子树，右子树进栈（右子树优先于父节点）
        if(root->right != nullptr){
            TreeNode* r = root->right;
            s.push(r);
            while(r->left != nullptr){
                r = r->left;
                s.push(r);
            }
        }

        //访问除已经访问过的最小的点
        while(!s.empty()){
            root->left = nullptr;
            root->right = s.top();
            root = root->right;
            s.pop();

            //右子树进栈（右子树优先于父节点）
            if(root->right != nullptr){
                TreeNode* r = root->right;
                s.push(r);
                while(r->left != nullptr){
                    r = r->left;
                    s.push(r);
                }
            }    
        }

        //尾巴要干净
        root->left = nullptr;
        root->right = nullptr;
        return ori_root;
    }
};

//递归写法
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        // cout<<root->left<<' '<<root<<' '<<root->right<<' '<<root->val<<endl;
        TreeNode* mid_root = root;
        if(root->left != nullptr){
            root = increasingBST(root->left);
            TreeNode* left_tail = root;
            while(left_tail->right != nullptr) left_tail = left_tail->right;
            left_tail->right = mid_root;
            mid_root->left = nullptr;
        }

        if(mid_root->right != nullptr){
            mid_root->right = increasingBST(mid_root->right);
        }

        if(root->left == nullptr && root->right == nullptr) return root;
        return root;
    }
};