class MyHashSet {
public:
    vector<int> hash;
    int mod;
    MyHashSet() : hash(1e4 + 1, -1), mod(1e4 + 1) {}
    void add(int key) {
        int index=key%mod;
        while(hash[index]!=-1 && hash[index] != key){
            index = (index + 1) % mod;
        }
        hash[index]=key;
    }
    
    void remove(int key) {
        int m=mod-1;
        while(m>=0){
            if(hash[m]==key) hash[m]=-1;
            m--;
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<hash.size();i++){
            if(key==hash[i]) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */