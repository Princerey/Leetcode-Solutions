class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> values;
    int lastIndex=0;
    RandomizedSet() {
    }
    bool insert(int val) {
        if(hash.find(val)==hash.end()){
            if(values.size()==lastIndex)
                values.push_back(val);
            else
                values[lastIndex]=val;
            
            hash[val]=lastIndex;
            lastIndex++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(hash.find(val)!=hash.end()){
            int index=hash[val];
            swap(values[index],values[lastIndex-1]);
            hash[values[index]]=index;
            hash.erase(val);
            --lastIndex;
            return true;
        }
        return false; 
    }
    
    int getRandom() {
        int rIndex=rand();
        rIndex=rIndex%(lastIndex);
        return values[rIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */