// 二叉搜索树：任意节点的左子树的节点都比右子树的小（或者大）
// 中序遍历：左中右顺序
// 减少内存消耗的方法：一路访问左子树压栈到底，每次访问右节点然后访问左子树压栈到底，next指针即栈顶指针

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
class BSTIterator {
    stack<TreeNode* > s;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root->left;
        }
        root = new TreeNode(-1);
        s.push(root);
        
    }
    
    int next() {
        TreeNode* root = s.top();
        s.pop();
        if(root->right){
            root = root->right;
            while(root){
                s.push(root);
                root = root->left;
            }
        }
        return s.top()->val;
    }
    
    bool hasNext() {
    return s.size()==1&&s.top()->right==NULL ? false:true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */