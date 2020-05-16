// HashMap.cpp
#include "HashMap.hpp"
#include <iostream>
#include <tuple>


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


HashMap::~HashMap()
{
    // delete[] buckets;
    for (unsigned int i=0;i<cap;++i)
    {
        delete buckets[i];
    }
    delete[] buckets;
}



void HashMap::add(const std::string& key, const std::string& value)
{
    // unsigned int hash_val = hashFunction(key);
    // unsigned int hash_bucket = hash_val % cap;
    unsigned int hash_bucket = get_hash(key, cap);
    // std::cout << key << " Hash value is " << hash_bucket << std::endl;
    // std::cout << hash_val << "   " << hash_bucket <<std::endl;
    if (contains(key) == false)
    {
        Node* new_node = new Node{key,value,nullptr};
        if (buckets[hash_bucket] == nullptr)
        {
            buckets[hash_bucket] = new_node;
            sz++;
            

        }
        else
        {
            // Node* head = buckets[hash_bucket]; 
            Node* ll = buckets[hash_bucket];
            while (ll->next!=nullptr)
            {
                // head = ll;
                ll = ll->next;
                
            }
            // Node* new_node = new Node{key,value,nullptr};
            ll->next = new_node;
            // head->next = new_node;
            // buckets[hash_bucket] = ll;
            sz++;
         
        } 
    }
    
}


bool HashMap::remove(const std::string& key)
{
    if (contains(key) == true)
    {
        
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
    for (unsigned int i=0;i<cap;++i)
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