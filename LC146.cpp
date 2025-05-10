#include "MyLib.h"

class LRUCache {
    struct Node {
        int k;
        int val;
        size_t next;
    };

    std::vector<Node> _data;
    std::unordered_map<int, size_t> key_prev_pos_map;
    int tail_key;

    void visit(decltype(key_prev_pos_map)::iterator& prev_it) {
        if (0 == prev_it->second) {
            return;
        }
        Node& prev = _data[prev_it->second];
        Node& curr = _data[prev.next];
        size_t curr_index = prev.next;
        prev.next = curr.next;
        curr.next = _data[0].next;
        _data[0].next = curr_index;

        auto it_curr = key_prev_pos_map.find(_data[curr.next].k);
        if (key_prev_pos_map.end() != it_curr) {
            it_curr->second = curr_index;
        }
        auto it_next = key_prev_pos_map.find(_data[prev.next].k);
        if (key_prev_pos_map.end() != it_next) {
            it_next->second = prev_it->second;
        }
        prev_it->second = 0;

        if (tail_key == curr.k) {
            tail_key = prev.k;
        }
    }

   public:
    LRUCache(int capacity) {
        _data.resize(capacity + 1);
        tail_key = -1;
    }

    int get(int key) {
        auto it = key_prev_pos_map.find(key);
        if (key_prev_pos_map.end() == it) {
            return -1;
        }

        Node& prev = _data[it->second];
        Node& curr = _data[prev.next];

        visit(it);
        // if (0 == it->second) {
        //     return curr.val;
        // }

        // size_t curr_index = prev.next;
        // prev.next = curr.next;
        // curr.next = _data[0].next;
        // _data[0].next = curr_index;

        // key_prev_pos_map[_data[curr.next].k] = curr_index;
        // key_prev_pos_map[_data[prev.next].k] = it->second;
        // it->second = 0;

        // if (tail_key == key) {
        //     tail_key = prev.k;
        // }

        return curr.val;
    }

    void put(int key, int value) {
        // find key
        auto it = key_prev_pos_map.find(key);
        if (key_prev_pos_map.end() != it) {
            Node& prev = _data[it->second];
            Node& curr = _data[prev.next];
            curr.val = value;
            visit(it);
            return;
        }

        // todo: first time cannot find tail_key
        auto it_old_tail = key_prev_pos_map.find(tail_key);
        if (key_prev_pos_map.end() == it_old_tail) {
            std::cerr << std::format("tail_key={} not in map!\n", tail_key);
            exit(0);
            return;
        }
        Node& prev = _data[it_old_tail->second];
        Node& curr = _data[prev.next];

        // append key
        int prev_n = key_prev_pos_map.size();
        if (prev_n + 1 < _data.size()) {
            curr.next = prev_n + 1;
            _data[prev_n + 1].k = key;
            _data[prev_n + 1].val = value;
            auto [it_new, _] = key_prev_pos_map.emplace(key, prev.next);
            tail_key = key;
            visit(it_new);
            return;
        }

        // replace tail

        curr.k = key;
        curr.val = value;
        auto [it_new, _] = key_prev_pos_map.emplace(key, it_old_tail->second);
        key_prev_pos_map.erase(it_old_tail);
        tail_key = key;
        visit(it_new);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */