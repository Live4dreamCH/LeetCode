#include "MyLib.h"

class LRUCache {
    struct Node {
        int k;
        int val;
        int next;
        int prev;
    };

    std::vector<Node> _data;
    std::unordered_map<int, int> key_pos_map;

    void visit(decltype(key_pos_map)::iterator& curr_it) {
        const int& curr_index = curr_it->second;
        Node& curr = _data[curr_index];
        if (0 == curr.prev) {
            return;
        }

        Node& prev = _data[curr.prev];
        Node& nxt = _data[curr.next];
        prev.next = curr.next;
        nxt.prev = curr.prev;

        Node& new_nxt = _data[_data[0].next];
        curr.next = _data[0].next;
        new_nxt.prev = curr_index;
        curr.prev = 0;
        _data[0].next = curr_index;
    }

   public:
    LRUCache(int capacity) { _data.resize(capacity + 1); }

    int get(int key) {
        auto it = key_pos_map.find(key);
        if (key_pos_map.end() == it) {
            return -1;
        }
        visit(it);

        Node& curr = _data[it->second];
        return curr.val;
    }

    void put(int key, int value) {
        // find key
        auto it = key_pos_map.find(key);
        if (key_pos_map.end() != it) {
            Node& curr = _data[it->second];
            curr.val = value;
            visit(it);
            return;
        }

        // append key
        if (key_pos_map.size() + 1 < _data.size()) {
            const int curr_index = key_pos_map.size() + 1;
            Node& curr = _data[curr_index];
            curr.k = key;
            curr.val = value;
            curr.next = _data[0].next;
            curr.prev = 0;

            Node& nxt = _data[curr.next];
            nxt.prev = curr_index;

            _data[0].next = curr_index;

            key_pos_map.emplace(key, curr_index);
            return;
        }

        // replace tail
        const int curr_index = _data[0].prev;
        Node& curr = _data[curr_index];
        size_t cnt = key_pos_map.erase(curr.k);
        curr.k = key;
        curr.val = value;
        auto [it_new, _] = key_pos_map.emplace(key, curr_index);
        visit(it_new);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */