class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        
        Node* currentLevel = root;
        
        while (currentLevel != NULL && currentLevel->left != NULL) {
            Node* curr = currentLevel;
            
            while (curr != NULL) {
                curr->left->next = curr->right;
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            
            currentLevel = currentLevel->left;
        }
        return root;
    }
};
