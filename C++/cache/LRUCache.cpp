#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;


/*************************************BY HACKER RANK*******************************************/
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};


/*************************************BY HACKER RANK*******************************************/


/*LRUCache Class*/
/*Author: ronny macmaster */
class LRUCache: public Cache{
  private:
    std::set<int> keylog; // key dictionary
  public:
    LRUCache(int cap = 1){// note : 0 is an invalid capacity
        cp = cap;
        head = tail = NULL;
    }
    void set(int key, int val){
        Node *data = new Node(key, val);
        if(keylog.find(key) == keylog.end()){ // key not yet in set
           Node *curr, *prev;
           keylog.insert(key);
           mp.insert({key, data});
           if(keylog.size() > cp){ // full capacity, take out the trash (pop_back)
               curr = tail->prev;
               keylog.erase(curr->key);
               mp.erase(curr->key);
               if(curr == NULL){
                   head = tail = NULL;
               }
               else{
                   tail = curr;
                   curr->next = NULL;
               }
              delete curr;
           }
           
           // empty cache?
           head == NULL ? tail = data : head->prev = data;
           // add new data
           data->prev = NULL;
           data->next = head;
           head = data;
        }
        else{ // key already in set
            Node *before, *after;
            Node *data = mp[key];
            before = data->prev;
            after = data->next;
            
            // fetch node
            after == NULL ? tail = data->prev : after->prev = data->prev;
            before == NULL ? head = data : before->next = data->next;
            
            // update old key node
            data->value = val;
            data->prev = NULL;
            data->next = head->next;
            head = data;
        } 
    }
    int get(int key){
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            Node *val_node = mp[key];
            return val_node->value;
        }
    }
    
};