class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int res = -1;
        
        while(root != nullptr) {
            if(root->data == x) return x;
            if(root->data > x) {
               res = root->data;
               root = root->left;
            }
            else root = root->right;
            
        }
        return res;
    }
};
