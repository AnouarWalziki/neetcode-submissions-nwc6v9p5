class LRUCache {
public:
    LRUCache(int capacity) : m_size(0), m_capacity(capacity){
        
    }
    
    int get(int key) {
        if(!m_values.contains(key)){
            return -1;
        }
        
        // make this key recent (back of the list)
        moveKeyToBack(key);

        return m_values[key].second;
    }
    
    void put(int key, int value) {
        if(m_values.contains(key)){
            // update value and make it recent
            m_values[key].second = value;
            moveKeyToBack(key);
            return;
        }

        // add new key
        auto it = m_keys.insert(m_keys.end(), key);
        m_values[key].first = it;
        m_values[key].second = value;
        m_size++;

        if(m_capacity < m_size){
            // cache is full so we have to remove least used
            int key = m_keys.front();
            auto it = m_values[key].first;
            m_values.erase(key);
            m_keys.erase(it);
        }
    }

private:
    unordered_map<int, pair<list<int>::iterator, int>> m_values;
    list<int> m_keys;
    int m_size;
    int m_capacity;

    void moveKeyToBack(int key){
        auto it = m_values[key].first;
        m_keys.erase(it);
        auto newIt = m_keys.insert(m_keys.end(), key);
        m_values[key].first = newIt;
    }
};
