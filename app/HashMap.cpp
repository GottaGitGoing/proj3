// HashMap.cpp
#include "HashMap.hpp"
#include <iostream>


namespace
{
    unsigned int ascii_hash(const std::string& s)
    {
        int hash_value = 0;
        for (int i=0; i<s.size();++i)
        {
            hash_value = 31*hash_value + s[i];
        }
        return hash_value;
    
    
    }

    // void HashMapCopy(Node* target, Node* source, unsigned int size)
    // {
    //     for (unsigned int i = 0; i<size; ++i)
    //     {
    //         target[i] = source[i];
    //     }
    // }
}


HashMap::HashMap()
    :hashFunction{ascii_hash}, sz{0}, cap{INITIAL_BUCKET_COUNT}, buckets{new Node*[INITIAL_BUCKET_COUNT]}
{
    for (unsigned int i=0;i<cap;++i)
    {
        buckets[i] = nullptr;
    }
    // std::cout << " Const " << hashFunction("Boo") << std::endl; 
}


HashMap::HashMap(HashFunction hashFunction)
    :hashFunction{hashFunction}, sz{0}, cap{INITIAL_BUCKET_COUNT}, buckets{new Node*[INITIAL_BUCKET_COUNT]}
{
    for (unsigned int i=0;i<cap;++i)
    {
        buckets[i] = nullptr;
    }
}


HashMap::HashMap(const HashMap& hm)
    :hashFunction{hm.hashFunction}, sz{hm.sz}, cap{hm.cap}, buckets{new Node*[hm.cap]}
{
    for (unsigned int i=0; i<hm.cap; ++i)
    {
        buckets[i] = hm.buckets[i];
    }
    
}


HashMap::~HashMap()
{
    // delete[] buckets;
    for (unsigned int i=0;i<cap;++i)
    {
        
        delete buckets[i];
    }
    delete[] buckets;
}



HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        Node** new_buckets = new Node*[hm.cap];
        for (unsigned int i=0; i<hm.cap; ++i)
        {
            new_buckets[i] = hm.buckets[i];
        }
        // (*this).~HashMap();
        sz = hm.sz;
        cap = hm.cap; 
        hashFunction = hm.hashFunction;          
        buckets = new_buckets;
    }

    return *this;
}




void HashMap::add(const std::string& key, const std::string& value)
{
    // unsigned int hash_bucket = get_hash(key, cap);

    if (contains(key) == false)
    {        
        // std::cout << " Hash val " << loadFactor() << std::endl;
        (*this).add_node(key,value,cap);

        if (loadFactor() >0.8)
        {
            const unsigned int old_cap = cap;
            unsigned int new_cap = 2*cap +1;
            Node** new_bucket = new Node*[new_cap];
            for (unsigned int i=0;i<new_cap;++i)
            {
                new_bucket[i] = nullptr;
            }
            
            for (unsigned int i=0; i<old_cap; ++i) // Go into each bucket
            {
                Node* ll = buckets[i];
                while (ll != nullptr)
                {
                    unsigned int hash_bucket = get_hash(ll->key,new_cap);
                    Node* new_node = new Node{ll->key,ll->value,nullptr};
                    
                    if (new_bucket[hash_bucket] == nullptr)
                    {
                        new_bucket[hash_bucket] = new_node; 
                        
                        
                    }
                    
                    else
                    {
                        Node* sec_ll = new_bucket[hash_bucket];
                        while (sec_ll->next!=nullptr)
                        {
                            sec_ll = sec_ll->next;    
                        }
                        sec_ll->next = new_node;
                    }  
                    ll = ll->next;
                
                }
            }
            for (unsigned int i=0;i<cap;++i)
            {
                delete buckets[i];
            }
            delete[] buckets;
            cap = new_cap;
            buckets = new_bucket;
                        
        }
    }
    
}


bool HashMap::remove(const std::string& key)
{
    if (contains(key) == true)
    {

        unsigned int hash_bucket = get_hash(key,cap);
        Node* ll = buckets[hash_bucket];
        Node* head = ll;
        
        if (ll->key == key)
        {
            head = ll->next;
            buckets[hash_bucket] = head;
            sz--;
            delete ll;
            return true;
        }
        while (ll !=nullptr && ll->key !=key)
        {
            // while they're both not on the same value keep looping (Note they break at a null == null)
            head = ll;
            ll = ll->next;
        }
        if (ll == nullptr)
        {
            delete ll;
            return false;
        }
        else
        {
            head->next = ll->next;
            sz--;
            return true;
        }       
         
    }
    return false;
}


bool HashMap::contains(const std::string& key) const
{
    // unsigned int hash_val = hashFunction(key);
    // unsigned int hash_bucket = hash_val % cap;
    unsigned int hash_bucket = get_hash(key, cap);
    // std::cout << " The hash bucket func right?  " << hash_bucket << std::endl;
    // std::cout << hash_val << "   " << hash_bucket <<std::endl;
    Node* ll = buckets[hash_bucket]; // buckets is **, an element of bucket is *
    while (ll != nullptr)
    {
        if ((*ll).key == key)
        {
            return true;
        }
        ll = (*ll).next;
    }
    return false;
    
}


std::string HashMap::value(const std::string& key) const
{
    
    if (contains(key) == true)
    {
        unsigned int hash_bucket = get_hash(key,cap);
        Node * ll = buckets[hash_bucket];
        while (ll != nullptr)
        {
            // std::cout<< ll->value << std::endl;
            if ((*ll).key == key )
            {
                return (*ll).value;
            }
            else
            {
                ll = ll->next;
            }
            
        }
    }
    return "";
}



unsigned int HashMap::size() const
{
    return sz;
}

unsigned int HashMap::bucketCount() const
{
    unsigned int allocated_buckets = 0;
    for (unsigned int i=0;i<this->cap;++i)
    {
        if(buckets[i] != nullptr)
        {
            allocated_buckets+= 1;
        }
    }
    return allocated_buckets;
}

double HashMap::loadFactor() const
{  
    return double(sz)/double(cap);
}

unsigned int HashMap::maxBucketSize() const
{
    auto c = findLargestBucket();
    return c;
}

unsigned int HashMap::findLargestBucket() const
{
    unsigned int current_max_index = 0; // find the index containing biggest bucket
    unsigned int current_max_nodes = 0; // count the nodes the max index has
    
    unsigned int temp_max_nodes = 0; 
    
    for (unsigned int i=0; i<cap;++i)
    {
        Node* ll = buckets[i];
        while (ll != nullptr)
        {
            temp_max_nodes+=1;
            ll = (*ll).next;
        }
        if (temp_max_nodes >= current_max_nodes)
        {
            current_max_nodes = temp_max_nodes;
            current_max_index = i;
        }
        temp_max_nodes = 0;
    }
    return current_max_nodes;
}


unsigned int HashMap::get_hash(const std::string& key, const unsigned int& capac) const
    {
        unsigned int hash_val = hashFunction(key);
        // std::cout << hash_val << " from name spae " << std::endl;
        unsigned int hash_bucket = hash_val % capac;
        return hash_bucket;
    }


void HashMap::add_node(const std::string& key, const std::string& value, const unsigned int& acap)
{
        unsigned int hash_bucket = get_hash(key, acap);
        std::cout << " Hash BUcket is " << hash_bucket << std::endl;
        Node* new_node = new Node{key,value,nullptr};
        if (buckets[hash_bucket] == nullptr)
        {
            buckets[hash_bucket] = new_node;
            sz++; 
        }
        else
        {
            Node* ll = buckets[hash_bucket];
            while (ll->next!=nullptr)
            {
                ll = ll->next;    
            }
            ll->next = new_node;
            sz++;
        
        }  
}