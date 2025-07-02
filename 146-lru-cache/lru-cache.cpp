class LRUCache
{
private:
    struct Node 
    {
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val): key(key)
                                , val(val)
                                , prev(NULL)
                                , next(NULL) 
                                {}
    };

    int size;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node)
    {
       //if(head!=node)
        {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    }

public:
    LRUCache(int capacity)
        : size(0)
        , capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) 
    {
        if (!cache.contains(key)) 
        {
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
       // if(head !=node)
        addToHead(node);
        return node->val;
    }

    void put(int key, int value) 
    {
        if (cache.contains(key)) 
        {
            Node* node = cache[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } 
        else 
        {
            if (size == capacity) 
            {
                Node *node = tail->prev;
                removeNode(node); //remove the last(but one?)entry from the doubly list
                cache.erase(node->key);//erase from the hash map
                size--;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            size++;//increment the page count
        }
    }
};