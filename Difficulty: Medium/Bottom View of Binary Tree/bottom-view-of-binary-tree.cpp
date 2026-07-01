/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
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
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            Node* temp = curr.first;
            int idx = curr.second;
            
            mp[idx] = temp -> data;
            if(temp -> left) q.push({temp -> left, idx - 1});
            if(temp -> right) q.push({temp -> right, idx + 1});
        }
        for(auto it : mp) 
            ans.push_back(it.second);
        return ans;
    }
};