/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        vector<int> nodes;
        
        while(root != nullptr) {
            nodes.push_back(root -> data);
            
            Node* temp = root -> bottom;
            while(temp != nullptr) {
                nodes.push_back(temp -> data);
                temp = temp -> bottom;
            }
            
            root = root -> next;
        }
        
        sort(nodes.begin(), nodes.end());
        
        //Now make a LL from the given sorted nodes;
        Node* head = new Node(nodes[0]);
        Node* curr = head;
        
        for(int i = 1; i < nodes.size(); i++) {
            curr -> bottom = new Node(nodes[i]);
            curr = curr -> bottom;
        }
        
        return head;
        
    }
};