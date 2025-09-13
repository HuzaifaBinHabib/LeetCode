class LRUCache {
public:
    class node{
      public:
      int key;
      int val;
      node* next;
      node* prev;
      node(int k , int v){
           key =k;
           val=v;
           next= prev =nullptr;
      }
    };
     int limit;
     node* head = new node(-1,-1);
     node* tail = new node(-1,-1);
     unordered_map<int,node*>m;

    void addnode(node* h1){
       node* temp  = head->next;
       head->next =h1;
       h1->next =temp;
       temp->prev  = h1;
       h1->prev =head;

    }
    
    void deletenode(node* h1){
        node* first = h1->next;
        node* second = h1->prev;
        
        second->next =first;
        first->prev = second;

    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;  
    }
    
    int get(int key) {
      if(m.find(key)== m.end()){
         return -1;
      }
      node* newnode = m[key];
      int ans = newnode->val;

      m.erase(key);
      deletenode(newnode);

      addnode(newnode);
      m[key]=newnode;

      return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!= m.end()){
            node* oldnode = m[key];
            m.erase(key);
            deletenode(oldnode);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
       node* newnode = new node(key,value);
       addnode(newnode);
       m[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */