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
class Solution
{
private:
    bool getPath(TreeNode* root, int value, string& path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == value) {
            return true;
        }
        path += 'L';
        if (getPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();
        path += 'R';
        if (getPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string a, b;
        getPath(root, startValue, a);
        getPath(root, destValue, b);
        int i=0;
        while(a[i]==b[i])
        {
            a[i]='*';
            b[i]='*';
            i++;
        }
        for(int i=0 ; i<a.size() ; i++)
        {
            if(a[i]!='*')
            {
                a[i]='U';
            }
        }
        a+=b;
        string Res="";
        for(int i=0 ; i<a.size() ; i++)
        {
            if(a[i]!='*')
            {
                Res+=a[i];
            }
        }
        return Res;
    }
};