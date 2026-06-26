class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {

private:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];

        // delete this node
        deleteNode(node);
        // and then insert it next after head;
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {

                Node* node = tail->prev;

                mpp.erase(node->key);
                deleteNode(node);
            }

            Node* node = new Node(key, value);

            insertAfterHead(node);
            mpp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */