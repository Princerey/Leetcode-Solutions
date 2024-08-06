class LRUCache {
unordered_map<int,int> keyToValue, keyToFrequency;
deque<int> sequenceOfKeys;
int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!keyToValue.count(key))
            return -1;
        keyToFrequency[key]++;
        sequenceOfKeys.push_back(key);
        return keyToValue[key];
    }
    
    void put(int key, int value) {
        sequenceOfKeys.push_back(key);
        keyToFrequency[key]++;
        while(keyToFrequency.size()>capacity){
            int firstInSequence=sequenceOfKeys.front();
            sequenceOfKeys.pop_front();
            if(--keyToFrequency[firstInSequence]==0){
                keyToFrequency.erase(firstInSequence);
                keyToValue.erase(firstInSequence);
            }
        }
        keyToValue[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */