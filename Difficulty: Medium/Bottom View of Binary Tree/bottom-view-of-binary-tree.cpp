/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == nullptr)
            return ans;
            
        //Create a map to store the bottom node for each vertical index
        map<int, int> mpp; //Index as key and node as value;
        
        //Make a queue for BFS with a pair having the node and vertical index
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int idx = it.second;
            
            mpp[idx] = node->data; //for the idx put the value of the corresponding node
            
            //If the left child exists then push it with vertical idx - 1
            if(node->left != nullptr) {
                q.push({node->left, idx - 1});
            }
            
            //If the right child exists then push it with vertical idx + 1
            if(node->right != nullptr) {
                q.push({node->right, idx + 1});
            }
            
        }
        
        //Put values of mp in ans array
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
            
    }
};