class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        
        Node(int cnt = 0) : count(cnt), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<string, Node*> keyToNode;
    
    Node* head;
    Node* tail;
    
    void insertAfter(Node* existingNode, Node* newNode) {
        newNode->next = existingNode->next;
        newNode->prev = existingNode;
        
        if (existingNode->next) {
            existingNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
        
        existingNode->next = newNode;
    }
    
    void insertBefore(Node* existingNode, Node* newNode) {
        newNode->prev = existingNode->prev;
        newNode->next = existingNode;
        
        if (existingNode->prev) {
            existingNode->prev->next = newNode;
        } else {
            head = newNode;
        }
        
        existingNode->prev = newNode;
    }
    
    void removeNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        
        delete node;
    }
    
public:
    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyToNode.count(key) == 0) {
            if (head->next->count == 1) {
                head->next->keys.insert(key);
                keyToNode[key] = head->next;
            } else {
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                insertAfter(head, newNode);
                keyToNode[key] = newNode;
            }
            return;
        }
        
        Node* currNode = keyToNode[key];
        currNode->keys.erase(key);
        
        Node* nextNode = currNode->next;
        if (nextNode->count != currNode->count + 1) {
            nextNode = new Node(currNode->count + 1);
            insertAfter(currNode, nextNode);
        }
        
        nextNode->keys.insert(key);
        keyToNode[key] = nextNode;
        
        if (currNode->keys.empty() && currNode->count > 0) {
            removeNode(currNode);
        }
    }
    
    void dec(string key) {
        Node* currNode = keyToNode[key];
        currNode->keys.erase(key);
        
        if (currNode->count == 1) {
            keyToNode.erase(key);
        } else {
            Node* prevNode = currNode->prev;
            
            if (prevNode->count != currNode->count - 1) {
                prevNode = new Node(currNode->count - 1);
                insertBefore(currNode, prevNode);
            }
            
            prevNode->keys.insert(key);
            keyToNode[key] = prevNode;
        }
        
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        return tail->prev != head ? *(tail->prev->keys.begin()) : "";
    }
    
    string getMinKey() {
        return head->next != tail ? *(head->next->keys.begin()) : "";
    }
    
    ~AllOne() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
