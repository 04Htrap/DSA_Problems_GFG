// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int res = -1;
        
        while(root != nullptr) {
            if(root->data == x) return x;
            if(root->data < x) {
               res = root->data;
               root = root->right;
            }
            else root = root->left;
            
        }
        return res;
    }
};