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
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode* root) {
        init(root);
    }
    
    
    /** @return the next smallest number */
    int next() {
        TreeNode* temp = st.pop();
        if(temp->right!= NULL)
        {
            init(temp->right);
        }

    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(st.empty());        
    }

    private:
    void init(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */