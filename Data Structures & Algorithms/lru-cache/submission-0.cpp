class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int k, int v) : 
    key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    int cap;
    Node* left;
    Node* right;
    void insert(Node* newNode){
        Node* bright = this->right->prev;
        bright->next = newNode;
        newNode->prev = bright;
        this->right->prev = newNode;
        newNode->next = this->right;
       
    }
    void remove(Node* target){
        Node* prev = target->prev;
        Node* next = target->next;
        prev->next = next;
        next->prev = prev;
        target->next = nullptr;
        target->prev = nullptr;
       
    }
    
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->left = new Node(0,0);
        this->right = new Node(0,0);
        this->left->next = this->right;
        this->right->prev = this->left;
    }
    
    int get(int key) {
        if(this->cache.find(key) != this->cache.end()){
            Node* node = this->cache[key];
            this->remove(node);
            this->insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(this->cache.count(key)){
            Node* node = this->cache[key];
            node->val = value;
            this->remove(node);
            this->insert(node);
            return;
        }
        if(this->cache.size() == this->cap){
            Node* del = this->left->next;
            this->remove(del);
            this->cache.erase(del->key);
            delete del;
        }
        Node* newNode = new Node(key, value);
        this->cache[key] = newNode;
        this->insert(newNode);

    }
};
