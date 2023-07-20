#include<bits/stdc++.h>

class LRUCache

{

public:

 

    class node

        {

            public:

            int key;

            int val;

            node* prev;

            node* next;

 

            node(int _key,int value)

            {

                key=_key;

                val=value;

            }

        };

 

    node* head=new node(-1,-1);

    node* tail=new node(-1,-1);

 

    int cap;

    unordered_map<int,node*> m;
    LRUCache(int capacity)
    {
        // Write your code here

        cap=capacity;

        head->next=tail;

        tail->prev=head;

    }

 

    void addnode(node* newnode)

    {

        node* temp=head->next;

        newnode->next=temp;

        newnode->prev=head;

        head->next=newnode;

        temp->prev=newnode;

    }

 

    void nodedelete(node* delnode)

    {
        node* delprev = delnode->prev;

        node* delnext = delnode->next;

        delprev->next = delnext;

        delnext->prev = delprev;

    }

 

    int get(int key)

    {

        // Write your code here
        if(m.find(key)!=m.end())

        {

            node* resnode=m[key];

            int ans=resnode->val;

            m.erase(key);

            nodedelete(resnode);

            addnode(resnode);

            m[key]=head->next;

            return ans;

        }

        return -1;

    }

 

    void put(int key, int value)

    {

        // Write your code here

        if(m.find(key)!=m.end())

        {

            node* del=m[key];

            m.erase(key);

            nodedelete(del);

        }

        if(m.size()==cap)

        {
            m.erase(tail->prev->key);

            nodedelete(tail->prev);
        }

        addnode(new node(key,value));

        m[key]=head->next;

    }

};

 
